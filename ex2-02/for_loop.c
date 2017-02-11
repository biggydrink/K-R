/*
 * for_loop.c
 *
 *  Created on: Jun 18, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-1
 * Write a loop equivalent to the for loop above without using && or ||.
 *
 * -The for loop above:
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i;
 * 		s[i] = c;
 */

/* First thoughts
 * Probably will use a while loop, and check the criteria in order with if statements.
 */

/* Second thoughts
 * Like I thought, it was pretty easy to implement this as a while loop with nested if statements, and
 * actually just as easy as a for loop. However, these are slightly different than the original loop,
 * as they do not break when one of the next if statements is not true--it just continues until "i"
 * is less than lim-1. Maybe instead of nested if statements, it should be nested while loops? Of course
 * the obvious answer is a break statement of some kind, but I don't think we've covered those yet in this
 * book, so there should be a way to do it without them. Maybe if-else statements, or maybe at some point
 * in the loop, c should get assigned EOF... hmm
 */

/* Final thoughts
 * Went with a manual loop, using the (sort of) boolean variable state, so I could exit the loop
 * whenever I wanted. Also added a few lines at the end to make it like the original getline() function,
 * and so I could test it out. Could probably do this in a for loop just as easily, but while seems
 * to make senes to me right now.
 */

#include <stdio.h>

enum boolean { FALSE, TRUE };

int main() {
	int i, c;
	int lim = 1000;
	char s[1000];
	int state = TRUE; /* a manual condition for the while loop */

	/*
	for (i = 0; i<lim-1;++i) {
		if ((c = getchar()) != '\n')
			if (c != EOF)
				s[i] = c;
	}
	*/

	i = 0;
	while (state) {
		if (i < lim-1) {
			if ((c = getchar()) != '\n') {
				if (c != EOF) {
					s[i] = c;
					++i;
				} else
					state = FALSE;
			} else
				state = FALSE;
		} else
			state = FALSE;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	printf("%s",s);
	return 0;
}
