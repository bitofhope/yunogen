/*
 * A virtual Yuno generator.
 * 
 * Generates an adorable, widening portrait of the character
 * Yuno from Hidamari Sketch. The portrait keeps widening until
 * it reaches the edge of your terminal window.
 */

/*
 * Copyright © 2015 bitofhope <bitofhope@kapsi.fi>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#include <curses.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	int y, x;
	getmaxyx(stdscr, y, x);

	if (x < 7 || !y)
	{
		fprintf(stderr, "Terminal too small!\n");
		return 1;
	}

	// Print initial Yuno
	printw("(X '_')");

	// Widen
	for (int i = 5; i < x - 2 && (getch() != 'q'); i++)
	{
		mvprintw(0, i, "_')");
		refresh();
		sleep(1);
	}

	while (getch() == ERR)
	{
		continue;
	}

	endwin();

	return 0;
}

