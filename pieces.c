#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "pieces.h"
#include "shapes.h"
#include "board.h"

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
    p->x = 3;
    p->y = 0;
    p->current_rotation = 0;
    
    int shape = rand() % NUM_SHAPES;
    switch (shape) { /* maybe i'll tidy this up and put them all in an array */
        case 0 : 
            p->number_rotations = I_NUM_ROT;
            p->rotations = I_PIECE;
            break;
        case 1 :
            p->number_rotations = J_NUM_ROT;
            p->rotations = J_PIECE;
            break;
        case 2 :
            p->number_rotations = L_NUM_ROT;
            p->rotations = L_PIECE;
            break;
        case 3 :
            p->number_rotations = T_NUM_ROT;
            p->rotations = T_PIECE;
            break;
        case 4 :
            p->number_rotations = S_NUM_ROT;
            p->rotations = S_PIECE;
            break;
        case 5 :
            p->number_rotations = Z_NUM_ROT;
            p->rotations = Z_PIECE;
            break;
        default :
            p->number_rotations = O_NUM_ROT;
            p->rotations = O_PIECE;
    }

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

