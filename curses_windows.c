#include <curses.h>
#include <stdio.h>

#define STARTX 1
#define STARTY 1

#define WINHEIGHT 30
#define WINWIDTH 40

WINDOW *create_newwin(int height, int width, int starty, int startx);

int main(){
	WINDOW *WindowOne, *WindowTwo, *WindowThree;
	int startx, starty, width, height, ch;
	initscr(); //creates stdscr
	cbreak(); 
	refresh();
	
	keypad(stdscr, TRUE);
	
	//Starts color and sets "color pairs"
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	
	//COLS and LINES are macros for max lines and columns?
	printf("COLS: %d LINES: %d", COLS, LINES);
	
	//Creates windows with function create_newwin
	WindowOne = create_newwin(WINHEIGHT, WINWIDTH, STARTY, STARTX); 
	WindowTwo = create_newwin(WINHEIGHT, WINWIDTH, STARTY, STARTX + WINWIDTH + 2);
	WindowThree = create_newwin(WINHEIGHT / 2, WINWIDTH * 2 + 2, STARTY +  WINHEIGHT + 1, STARTX);
	
	//attron is only for standard window? Need to use wattron to set color for individual windows
	wattron(WindowOne, COLOR_PAIR(1));
	wattron(WindowTwo, COLOR_PAIR(2));
	wattron(WindowThree, COLOR_PAIR(3));
	
	//prints string to Window, x/y
	mvwprintw(WindowOne, 2, 2, "Röd text i fönster 1");
	mvwprintw(WindowTwo, 2, 2, "Grön text i fönster 2");
	mvwprintw(WindowThree, 2, 2, "Blå text i fönster 3");
	
	//refreshes windows to show text
	wrefresh(WindowOne);
	wrefresh(WindowTwo);
	wrefresh(WindowThree);
	
	
	//refresh();
	getch(); //Waits for user input, "pauses"
	endwin(); //ends curses
	return 0;
}

//Creates window, adds border, refreshes and returns the window pointer
WINDOW *create_newwin(int height, int width, int starty, int startx){
	WINDOW *w = newwin(height, width, starty, startx);
	box(w, ACS_VLINE , ACS_HLINE);
	wrefresh(w);
	return w;
}