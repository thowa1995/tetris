#include <ncurses.h>
#include <stdio.h>

#include "pieces.h"
#include "board.h"

#define NUM_L_ROT  4
int lPiece[NUM_L_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {1,1,1,0},
     {1,0,0,0},
     {0,0,0,0}},
     
    {{1,1,0,0},
     {0,1,0,0},
     {0,1,0,0},
     {0,0,0,0}},
      
    {{0,0,1,0},
     {1,1,1,0},
     {0,0,0,0},
     {0,0,0,0}},
      
    {{0,1,0,0},
     {0,1,0,0},
     {0,1,1,0},
     {0,0,0,0}} 

};

void draw_piece(struct Piece *p)
{
    for (int r = 0; r < PIECE_HEIGHT; r++) {
        for (int c = 0; c < PIECE_WIDTH; c++) {
            if (PIECE_BLOCKS(p)[r][c] == FILLED) {
                move(FIELD_Y + p->y + r, FIELD_X + 2*(c + p->x));
                printw("[]");
            }
        }
    }
}

void new_piece(struct Piece *p)
{
    p->x = 5;
    p->y = 5;
    p->current_rotation = 0;
    p->number_rotations = 4;
    p->rotations = lPiece;
    return;
}

/* locks a piece into the playfield */
void lock_piece(struct Piece *p, int (*pf)[FIELD_WIDTH])
{    
    for (int r = 0; r < PIECE_HEIGHT; r++) {
        for (int c = 0; c < PIECE_WIDTH; c++) {
            if (PIECE_BLOCKS(p)[r][c] == FILLED) {
                pf[p->y + r][p->x + c] = FILLED;
            }
            
        }
    }
}

/* return 1 if this piece is valid,
 * return 0 if any part of it is outside the playfield or collides with 
 * another block
 */
int valid(struct Piece *p, int (*pf)[FIELD_WIDTH])
{
    for (int r = 0; r < PIECE_HEIGHT; r++) {
        
        for (int c = 0; c < PIECE_WIDTH; c++) {
            if (PIECE_BLOCKS(p)[r][c] == FILLED) {
                move(1,1);
                if (   p->y + r < 0 || p->y + r >= FIELD_HEIGHT 
                    || p->x + c < 0 || p->x + c >= FIELD_WIDTH ) {
                    return 0;
                }
                if (pf[p->y + r][p ->x + c] == FILLED) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* rotate piece in the playfield */
/* returns 1 if successful, otherwise 0 */
int rotate(struct Piece *p, int (*pf)[FIELD_WIDTH])
{
    struct Piece tmp = *p;
    
    tmp.current_rotation = (tmp.current_rotation + 1) % tmp.number_rotations;
    if (valid(&tmp, pf)) {
        *p = tmp;
        return 1;
    }
    return 0;
}

/* moves piece leftwards in the playfield */
/* returns 1 if successful, otherwise 0 */
int move_left(struct Piece *p, int (*pf)[FIELD_WIDTH])
{
    struct Piece tmp = *p;
    
    tmp.x--;
    if (valid(&tmp, pf)) {
        *p = tmp;
        return 1;
    }
    return 0;
}

/* moves piece rightwards in the playfield */
/* returns 1 if successful, otherwise 0 */
int move_right(struct Piece *p, int (*pf)[FIELD_WIDTH])
{    
    struct Piece tmp = *p;
    
    tmp.x++;
    if (valid(&tmp, pf)) {
        *p = tmp;
        return 1;
    }
    return 0;
}

/* moves piece downwards in the playfield */
/* returns 1 if successful, otherwise 0 */
int move_down(struct Piece *p, int (*pf)[FIELD_WIDTH])
{    
    struct Piece tmp = *p;
    
    tmp.y++;
    if (valid(&tmp, pf)) {
        *p = tmp;
        return 1;
    }
    return 0;
}

