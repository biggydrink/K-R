/*
 * escape.c
 *
 *  Created on: Jul 16, 2015
 *      Author: andre_000
 */


/* K&R Exercise 3-2, 7/16/15
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape
 * sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
 * other direction as well, converting escape sequences into the real characters.
 *
 * Switch statement:
 *
 * switch (expression) {
 * 		case const-expr: statements
 * 		case const-expr: statements
 * 		default: statements
 * }
 */

/* First thoughts, 7/17/15
 * Seems fairly straightforward--I've created string copying functions for earlier exercises before.
 * Seems to mostly be a simple way to practice switch statements - we'll see if anything unexpected
 * comes up.
 */

/* Second thoughts, 7/18/15
 * It's working, and nothing too strange seems to be needed to get it to work. I liked
 * the challenge of figuring out how to keep track of your way through each of the
 * char strings, and it was fun to hear the bell character--the last time I heard that
 * was in DOS on a 386!
 */

#include <stdio.h>
#define LIMIT 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
	char s[LIMIT];
	char t[LIMIT];
	char u[LIMIT];
	int i, c;

	for (i = 0; (c = getchar()) != EOF && i<LIMIT-1; ++i)
		s[i] = c;
	s[i] = '\0';

	/* all the escapes */
	/*
	s[0] = '\a';	//alert (bell) character
	s[1] = '\b';	//backspace
	s[2] = '\f';	//formfeed
	s[3] = '\n';	//newline
	s[4] = '\r';	//carriage return
	s[5] = '\t';	//horizontal tab
	s[6] = '\v';	//vertical tab
	s[7] = '\\';	//backslash
	s[8] = '\?';	//question mark
	s[9] = '\'';	//single quote
	s[10] = '\"';	//double quote
	s[11] = '\0';
	*/

	printf("Original string s: %s\n",s);
	printf("Running escape() ...\n");
	escape(s,t);
	printf("Original string s: %s\n",s);
	printf("New string t with escapes: %s\n",t);
	printf("Running unescape() ...\n");
	unescape(t,u);
	printf("Escaped string t: %s\n",t);
	printf("New string u without escapes: %s\n",u);

	return 0;
}
/* escape(s,t)
 * copies s to t, and in the process changes all escape characters (e.x. newline, tab) to their visible
 * representations (e.x. "\n" and "\t")
 */
void escape(char s[], char t[]) {
	int i, j;

	j = 0;
	for (i = 0; s[i] != '\0'; ++i) {

		switch (s[i]) {
		case '\a':			//alert (bell) character
			t[j++] = '\\';
			t[j++] = 'a';
			break;
		case '\b':			//backspace
			t[j++] = '\\';
			t[j++] = 'b';
			break;
		case '\f':			//formfeed
			t[j++] = '\\';
			t[j++] = 'f';
			break;
		case '\n':			//newline
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\r':			//carriage return
			t[j++] = '\\';
			t[j++] = 'r';
			break;
		case '\t':			//horizontal tab
			t[j++] = '\\';
			t[j++] = 't';
			break;
		case '\v':			//vertical tab
			t[j++] = '\\';
			t[j++] = 'v';
			break;
		case '\\':			//backslash
			t[j++] = '\\';
			t[j++] = '\\';
			break;
		case '\?':			//question mark
			t[j++] = '\\';
			t[j++] = '?';
			break;
		case '\'':			//single quote
			t[j++] = '\\';
			t[j++] = '\'';
			break;
		case '\"':			//double quote
			t[j++] = '\\';
			t[j++] = '\"';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}

/* escape(s,t)
 * copies s to t, and in the process changes any visible representations of escape characters (e.x. "\n"
 * or "\t") to the characters themselves, newlines and tabs
 */
/* Notes after looking at answer key
 * Two improvements:
 * 1. If statement should be s[i] != '\\', since that is more common and thus most operations can
 * 		avoid the switch statement.
 * 2. Switch (s[i+1]) followed by ++i in every case is redundant - could just say switch (s[++i]).
 */
void unescape(char s[], char t[]) {
	int i, j;

	j = 0;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\\') {
			switch (s[i+1]) {
			case 'a':			//alert (bell) character
				t[j++] = '\a';
				++i;
				break;
			case 'b':			//backspace
				t[j++] = '\b';
				++i;
				break;
			case 'f':			//formfeed
				t[j++] = '\f';
				++i;
				break;
			case 'n':			//newline
				t[j++] = '\n';
				++i;
				break;
			case 'r':			//carriage return
				t[j++] = '\r';
				++i;
				break;
			case 't':			//horizontal tab
				t[j++] = '\t';
				++i;
				break;
			case 'v':			//vertical tab
				t[j++] = '\v';
				++i;
				break;
			case '\\':			//backslash
				t[j++] = '\\';
				++i;
				break;
			case '\?':			//question mark
				t[j++] = '\?';
				++i;
				break;
			case '\'':			//single quote
				t[j++] = '\'';
				++i;
				break;
			case '\"':			//double quote
				t[j++] = '\"';
				++i;
				break;
			default:
				break;
			}
		} else
			t[j++] = s[i];
	}
	t[j] = '\0';
}
