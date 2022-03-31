#ifndef PIECES_H
#define PIECES_H

#include "board.h"
/* each rotation of each piece will be represented by a 4x4 matrix,
 * this will accomodate the l piece and will save having to store
 * dimensions on each rotation */
#define PIECE_WIDTH  4
#define PIECE_HEIGHT 4


struct Piece {
    int x;
    int y;
    int current_rotation;
    int number_rotations; /* num rotations for this shape */
    int (*rotations)[PIECE_HEIGHT][PIECE_WIDTH];
};

#define PIECE_BLOCKS(x) x->rotations[x->current_rotation]

void draw_piece(struct Piece *p);

void new_piece(struct Piece *p);
void lock_piece(struct Piece *p, int (*pf)[FIELD_WIDTH]);
int rotate(struct Piece *p, int (*pf)[FIELD_WIDTH]);
int move_left(struct Piece *p, int (*pf)[FIELD_WIDTH]);
int move_right(struct Piece *p, int (*pf)[FIELD_WIDTH]);
int move_down(struct Piece *p, int (*pf)[FIELD_WIDTH]);

#endif
