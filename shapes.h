#include "pieces.h"

#ifndef SHAPES_H
#define SHAPES_H

#define NUM_SHAPES 7

#define I_NUM_ROT 2
const int I_PIECE[I_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {1,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,0,1,0},
     {0,0,1,0},
     {0,0,1,0}}
};

#define J_NUM_ROT 4
const int J_PIECE[J_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,1,1,1},
     {0,0,0,1},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,0,1,0},
     {0,1,1,0},
     {0,0,0,0}},
     
    {{0,1,0,0},
     {0,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
     
    {{0,0,1,1},
     {0,0,1,0},
     {0,0,1,0},
     {0,0,0,0}}
};

#define T_NUM_ROT 4
const int T_PIECE[T_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,1,1,1},
     {0,0,1,0},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,1,1,0},
     {0,0,1,0},
     {0,0,0,0}},
     
     {{0,0,1,0},
     {0,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,0,1,1},
     {0,0,1,0},
     {0,0,0,0}}
};

#define L_NUM_ROT 4
const int L_PIECE[L_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,1,1,1},
     {0,1,0,0},
     {0,0,0,0}},
     
    {{0,1,1,0},
     {0,0,1,0},
     {0,0,1,0},
     {0,0,0,0}},
     
    {{0,0,0,1},
     {0,1,1,1},
     {0,0,0,0},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,0,1,0},
     {0,0,1,1},
     {0,0,0,0}}
};

#define S_NUM_ROT 2
const int S_PIECE[S_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,0,1,1},
     {0,1,1,0},
     {0,0,0,0}},
     
    {{0,0,1,0},
     {0,0,1,1},
     {0,0,0,1},
     {0,0,0,0}}
};

#define Z_NUM_ROT 2
const int Z_PIECE[Z_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,1,1,0},
     {0,0,1,1},
     {0,0,0,0}},
     
    {{0,0,0,1},
     {0,0,1,1},
     {0,0,1,0},
     {0,0,0,0}}
};

#define O_NUM_ROT 1
const int O_PIECE[O_NUM_ROT][PIECE_HEIGHT][PIECE_WIDTH] = {
    
    {{0,0,0,0},
     {0,1,1,0},
     {0,1,1,0},
     {0,0,0,0}}
};

#endif


