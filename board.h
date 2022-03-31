#ifndef BOARD_H
#define BOARD_H

/* All board measurements are in blocks,
 * each block being two chars wide 
 */
#define FIELD_HEIGHT 20 /* the height of the playfield */
#define FIELD_WIDTH 10  /* the width of the playfield */
#define FIELD_X 20   /* x position of the top left block in the field */     
#define FIELD_Y 1   /* y position of the top left block in the field */

#define SIDE_WIDTH 2    /* thickness of the side columns in chars */

#define EMPTY  0    /* representing an empty block */
#define FILLED 1    /* representing a block that has been filled */

void draw_board(int (*pf)[FIELD_WIDTH]);

void new_play_field(int (*pf)[FIELD_WIDTH]);
int clear_rows(int (*pf)[FIELD_WIDTH]);

#endif
