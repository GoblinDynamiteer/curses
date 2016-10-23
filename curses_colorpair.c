#include <curses.h>
#include <stdio.h>

int main(){
	initscr(); //creates stdscr
	//raw(); 
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("Test");
	attroff(COLOR_PAIR(1));
	getch(); //pauses, waits for user input.
	endwin(); //ends curses
	return 0;
}