#include <ncurses.h>
#include <time.h>
#include "board.h"
#include "pieces.h"

#define DROP_RATE 1500
#define TIME(x) (1000*clock())/CLOCKS_PER_SEC;
int main(int argc, char *argv[])
{    
    /* a grid representing the playfield */
    int pf[FIELD_HEIGHT][FIELD_WIDTH];
    
    /* the piece that is currently falling */
    struct Piece curr;
    
    /* the last key pressed */
    int c = 0;
    
    /* for comparing time to the last drop time (in milliseconds) */
    clock_t now, last; 
    
    /* ncurses stuff */
    initscr();              /* init ncurses                 */
    timeout(0);             /* stops getch() from blocking  */
    keypad(stdscr, TRUE);   /* need this so arrow keys work */
    noecho();               /* don't print on getch()       */
    curs_set(0);            /* hide the cursor              */

    new_play_field(pf);
    new_piece(&curr);
    last = TIME();

    while (1) {
        
        /* if it's time to, then drop piece */
        now = TIME();        
        if (now > last + DROP_RATE) {
            /* if we can't move down then lock the piece */
            if(!move_down(&curr, pf)) {
                lock_piece(&curr, pf);
                clear_rows(pf);
                new_piece(&curr);
            }
            last = now;        
        }
        
        /* deal with input */
        c = getch();
        switch (c) {
            case KEY_UP     : rotate(&curr, pf);
                break;
            case KEY_LEFT   : move_left(&curr, pf); 
                break;
            case KEY_RIGHT  : move_right(&curr, pf);
                break;
            case KEY_DOWN   : move_down(&curr, pf);
                break;
        }
        
        draw_board(pf);
        draw_piece(&curr);
        refresh();          /* print buffer to screen */
    }
    
    endwin();

    return 0;
}
