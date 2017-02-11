/*
 * src.c
 *
 *  Created on: Jun 28, 2015
 *      Author: andre_000
 */


/* K&R Exercise 2-4
 * Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any
 * character in the string s2.
 *
 * The original squeeze() that the exercise is referencing:
 * /* squeeze: deletes all c from s *//*
 * void squeeze(char s[], int c)
 * {
 * 		int i, j;
 *
 * 		for (i = j = 0; s[i] != '\0'; i++)
 * 			if (s[i] != c)
 * 				s[j++] = s[i];
 * 		s[j] = '\0';
 * 		}
 */

/* Finished thoughts
 * This may not be the most optimized way to make this program, but the most important thing to me
 * for now was to get it to work. I also got more familiar with the ++ operator by doing this. There
 * are also potentially problems with the character lengths, and I've heard something like that
 * can be a security risk, but as of yet I don't know how that works, so for now I'm just doing
 * the exercise.
 */

#include <stdio.h>

enum boolean {INVALID, VALID};

void squeeze(char s[], char t[]);
void booksqueeze(char s[], char t[]);

int main() {
	char s[1000];
	char forbid[1000];
	int i, c;

	/*
	for (i = 0; (c = getchar()) != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';

	for (i = 0; (c = getchar()) != '\n'; ++i)
		forbid[i] = c;
	forbid[i] = '\0';
	*/

	s[0] = 't';
	s[1] = 'h';
	s[2] = 'i';
	s[3] = 's';
	s[4] = ' ';
	s[5] = 'i';
	s[6] = 's';
	s[7] = ' ';
	s[8] = 'm';
	s[9] = 'y';
	s[10] = ' ';
	s[11] = 's';
	s[12] = 't';
	s[13] = 'r';
	s[14] = 'i';
	s[15] = 'n';
	s[16] = 'g';
	s[17] = '.';
	s[18] = '\0';

	forbid[0] = 'a';
	forbid[1] = 'i';
	forbid[2] = 'u';
	forbid[3] = 'e';
	forbid[4] = 'o';
	forbid[5] = '\0';

	printf("Char s: %s\n\n",s);
	printf("These characters are forbidden: %s\n\n",forbid);

	booksqueeze(s,forbid);
	printf("Squeezed char s: %s\n",s);

	return 0;
}

/* squeeze: deletes all instances of any character in char t from char s. */
void squeeze(char s[], char t[]) {
	int i, j, k;
	int test;

	test = VALID;
	for (i = j = 0; s[i] != '\0'; i++) {
		for (k = 0; t[k] != '\0'; k++) {
			if (test == VALID) {
				if (s[i] != t[k])
					test = VALID;
				else
					test = INVALID;
			}
		}
		if (test == VALID)
			s[j++] = s[i];
		test = VALID;
	}
	s[j] = '\0';
}

void booksqueeze(char s[], char t[]) {
	int i, j, k;

	for (i = k = 0; s[i] != '\0'; i++) {
		for (j = 0; t[j] != '\0' && t[j] != s[i]; j++)
			;
		if (t[j] == '\0')
			s[k++] = s[i];
	}
	s[k] = '\0';
}
