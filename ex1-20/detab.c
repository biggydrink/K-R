/*
 * detab.c
 *
 *  Created on: May 12, 2015
 *      Author: andre_000
 */

/* K&R Exercise 1-20 (page 34)
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space
 * to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable
 * or a symbolic parameter?
 */

/* Not sure what "a fixed set of tab stops" means. Or "every n columns." Why are there any columns?
 * Where did they come from?
 * Got some help from stackoverflow: http://stackoverflow.com/questions/7178201/kr-exercise-1-20-need-some-clarification
 *
 * Looks like one tab in Eclipse is equal to 4 spaces.
 *
 * I would think that n should be a symbolic parameter. We don't really want it to be changeable within
 * the program, but when editing the program changing a symbolic parameter is as easy as changing a
 * variable. Also then n will always be at the top or in the header of a program (easy to find).
 */

#include <stdio.h>
#define COL 4

/*	*/ //tab
/*  */ //two spaces... looks like the tab stop is every 4 spaces, but if there are other characters
	   //they also count towards the 4 space count
//	hello	world	tab
//	hello   world	3 spaces
//	x	x	x	x	tabs
//	x   x   x   x   3 spaces
//  xxxxx
//	now	this	is	a	story	all	about	how
//	now this    is  a   story   all about   how
//  now	this	is	a	story	all	about	how	my	life	got	flip	turned	upside	down	and	i'd
//  now this    is  a   story   all about   how my  life    got flip    turned  upside  down    and i'd
//
int main() {

	int c, count, i;

	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (i = count; i < COL; ++i)
				putchar(' ');
			count = 0;
		}
		else {
			++count;
			if (count == COL || c == '\n')
				count = 0;
			putchar(c);
		}
	}
	return 0;
}
