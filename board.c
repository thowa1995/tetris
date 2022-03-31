#include "board.h"
#include "ncurses.h"

/* draws the board background */
void drawBg()
{
    for (int r = 0; r < FIELD_HEIGHT; r++) {
        
        move(FIELD_Y + r, FIELD_X - SIDE_WIDTH);
        
        /* print the left column */
        printw("<!");
        /* print all the dots for a row */
        for (int c = 0; c < FIELD_WIDTH; c++) {
            printw(" .");                            
        }
        /* print the right column */
        printw("!>");
    }
    
    move(FIELD_Y + FIELD_HEIGHT, FIELD_X - SIDE_WIDTH);
    
    /* print the bottom border */
    printw("<!");
    for (int c = 0; c < FIELD_WIDTH; c++) {
        printw("==");
    }
    printw("!>");
    move(FIELD_Y + FIELD_HEIGHT + 1, FIELD_X);
    for (int c = 0; c < FIELD_WIDTH; c++) {
        printw("\\/");
    }
}

/* draws the blocks */
void drawfg(int (*pf)[FIELD_WIDTH])
{
    for (int r = 0; r < FIELD_HEIGHT; r++) {
        for (int c = 0; c < FIELD_WIDTH; c++) {
            if (pf[r][c] == FILLED) {
                move(FIELD_Y + r, FIELD_X + 2*c);
                printw("[]");
            }
        }
    }
}

/* draws the background and then the blocks */
void draw_board(int (*pf)[FIELD_WIDTH])
{
    drawBg();
    drawfg(pf);
}

void new_play_field(int (*pf)[FIELD_WIDTH])
{
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            pf[i][j] = EMPTY;
        }
    }
}

/* clears a row, shifts all rows above downwards */
void clear_row(int (*pf)[FIELD_WIDTH], int row)
{
    for (int r = row; r > 0; r--) {
        for (int c = 0; c < FIELD_WIDTH; c++) {
            pf[r][c] = pf[r-1][c];
        }
    }
    
    /* special case for top row */
    for (int c = 0; c < FIELD_WIDTH; c++) {
        pf[0][c] = EMPTY;
    }
}

/* clears any full rows in the playfield */
/* returns the number of rows cleared */
int clear_rows(int (*pf)[FIELD_WIDTH])
{
    int count = 0;
    for (int r = 0; r < FIELD_HEIGHT; r++) {
        int full = 1; /* guard */
        for (int c = 0; c < FIELD_WIDTH; c++) {
            if (pf[r][c] != FILLED) {
                full = 0;
            }
        }
        if (full) {
            clear_row(pf, r);
            count++;
        }
    }
    return count;
}
