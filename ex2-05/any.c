/*
 * any.c
 *
 *  Created on: Jun 30, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-5
 * Write the function any(s1,s2), which returns the first location in the string s1 where any character
 * from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location).
 */

/* First thoughts, 6/30/15
 * Seems similar enough to squeeze that this shouldn't be too hard, unless I'm missing something.
 * Two for loops should do the job, one to cycle through s1, and one to cycle through s2 for each
 * char in s1. Second loop should stop as soon as it finds a match, and remember where in the loop it is.
 */

/* Second thoughts, 6/30/15
 * As I suspected, not quite as simple as I thought. I said that the second loop should stop as soon as
 * it finds a match, but in fact ideally the second AND the first loop would both stop when a match is
 * found. I implemented a workaround for now by adding a variable MATCH that is set to NO until it finds
 * a match. The loops then continue, which is a waste of time, and could be significant if each string is
 * long. This is a similar problem, and a similar solution, to my squeeze() function from ex2-4. The C
 * Answer Book had a better implementation than mine--I want to look at it again and fix my code to
 * something better. I'll add a revised any() (revany) function for the new implementation.
 */

/* Final thoughts, 7/11/15
 * I ended up making a third version of any, called newany(), that finally did what I originally
 * wanted by ending all loops as soon as a match is found, by making the first for loop contingent on
 * match being equal to NO. revany() was not as successful - the main thing I learned from the answer
 * book was that you can put a ; after a for loop to cause it to do nothing but run through the loop,
 * and that did not really help in this exercise. But I am happy with newany()
 *
 * Also, the answer book still had a more elegant solution--just return pos when the match is found, and
 * the function will automatically end. Oh well... I'll add this in too because it's nice - bookany()
 */

#include <stdio.h>

int any(char s[], char t[]);
int revany(char s[], char t[]);
int newany(char s[], char t[]);
int bookany(char s[], char t[]);

int main() {
	char s[1000];
	char t[1000];
	int i, j;
	int pos; /* position in s1 where a character from s2 was first encountered */

	j = 0;
	for (i='a'; i<'z'+1; ++j) {
		s[j] = i++;
	}
	s[j] = '\0';
	printf("%s\n",s);

	t[0] = 'k';
	t[1] = 'l';
	t[2] = 'b';
	t[3] = '\0';

	pos = newany(s,t);
	printf("%d\n",pos);

	return 0;
}
/* any()
 * Returns the first location in the string s1 where any character from the string s2 occurs, or -1 if
 * s1 contains no characters from s2.
 */
int any(char s[], char t[]) {
	enum boolean {NO, YES};

	int i, j;
	int pos; /* position in s1 where a character from s2 was first encountered */
	int match; /* whether we have found a match in s1 and s2 */

	match = NO;
	pos = -1; /* function returns EOF (-1) if the checks below fail */
	for (i=j=0;s[i] != '\0'; ++i)
		for (j=0;t[j] != '\0'; ++j)
			if (match == NO && s[i] == t[j]) {
				match = YES;
				pos = i;
			}

	return pos;
}

/* newany()
 * Returns the first location in the string s where any character from the string t occurs, or -1 if
 * s contains no characters from s2.
 * This is my third attempt to create a simplified version of any() that stops all loops once it
 * finds a match between s and t.
 */
int newany(char s[], char t[]) {
	enum boolean {NO, YES};

	int i, j;
	int pos; /* position in s1 where a character from s2 was first encountered */
	int match; /* whether we have found a match in s1 and s2 */

	match = NO;
	pos = -1;
	for (i=0;s[i] != '\0' && match == NO; ++i)
		for (j=0; t[j] != '\0'; ++j)
			if (match == NO && s[i] == t[j]) {
				match = YES;
				pos = i;
			}

	return pos;

}
/* revany()
 * Returns the first location in the string s1 where any character from the string s2 occurs, or -1 if
 * s1 contains no characters from s2.
 * This is a revised version of any() that takes into account some ideas from the answer to ex2-4 in the
 * C Answer Book.
 */
int revany(char s[], char t[]) {
	int i, j;
	int pos; /* position in s where a character from t was first encountered */

	pos = -1; /* function returns EOF (-1) if the checks below fail */
	for (i = j = 0; s[i] != '\0'; ++i) {
		for (j = 0; t[j] != '\0' && s[i] != t[j]; ++j)
			;
		if (s[i] == t[j]) {
			if (pos == -1)
				pos = i;
		}
	}

	return pos;
}

/* bookany()
 * The answer book's implementation of any()
 */
int bookany(char s[], char t[]) {
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
		for (j = 0; t[j] != '\0'; j++)
			if (s[i] == t[j])
				return i;
	return -1;
}
