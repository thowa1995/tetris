#include <ncurses.h>
#include <time.h>
#include "board.h"
#include "pieces.h"

int main(int argc, char *argv[])
{	
	/* a grid representing the playfield */
	int pf[FIELD_HEIGHT][FIELD_WIDTH];
	
	/* the piece that is currently falling */
	struct Piece curr;	
	
	new_play_field(pf);
	new_piece(&curr);
	
	/* ncurses stuff */
	initscr();				/* init ncurses */
	timeout(0);				/* stops getch() from blocking */
	keypad(stdscr, TRUE);	/* need this so arrow keys work */
	noecho();				/* don't print on getch() */
	curs_set(0);			/* hide the cursor */
	int c = 0;
	clock_t sec;
	while (1) {
		sec = clock()/CLOCKS_PER_SEC;
		move(2,2);
		printw("%d", sec);
		
		c = getch();
		switch (c) {
			case KEY_UP 	: rotate(&curr, pf); break;
			case KEY_LEFT 	: move_left(&curr, pf); break;
			case KEY_RIGHT	: move_right(&curr, pf); break;
		}
		
		draw_board(pf);
		draw_piece(&curr);
		refresh();			/* print buffer to screen */
	}
	/* ncurses stuff */
	
	endwin();

	return 0;
}
