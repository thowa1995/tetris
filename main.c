#include <ncurses.h>

#define HEIGHT 20
#define WIDTH 10
#define START_X 20 
#define START_Y 1 

void draw()
{
	for (r = 0; r < HEIGHT; r++) {
		move(START_Y + r, START_X );
		printw("<!");
		for (c = 0; c < WIDTH; c++) {
			printw(" .");
		}
		printw("!>");
	}
	move(START_Y + HEIGHT, START_X);
	printw("<!");
	for (c = 0; c < WIDTH; c++)
       	{
		printw("==");
	}
	printw("!>");
	move(START_Y + HEIGHT + 1, START_X + 2);
	for (c = 0; c < WIDTH; c++)
       	{
		printw("\\/");
	}
}

int main()
{	
	int r, c;
	
	initscr();
	curs_set(0);
	draw();
	refresh();
	getch();
	endwin();

	return 0;
}
