/*
 * 3-6.c
 *
 *  Created on: Dec 24, 2015
 *      Author: andre_000
 */


/* Exercise 3-6, page 64
 * Write a version of itoa that accepts three arguments instead of two. The third argument
 * is a minimum field width; the converted number must be padded with blanks on the left if necessary
 * to make it wide enough.
 */

/* Thoughts:
 * Make your own printf() function? Ha
 *
 * 2/11/17:
 * Just add a statement at the end that checks if the length is less than the specified width, and add spaces to the
 * end before reversing the array. Is it that simple?
 *
 * Seems to work!
 */


#include <stdio.h>
#include <string.h>

#define LIMIT 100

void bookitoa(int n, char s[]);
void reverse(char s[]);
void itoaMinWidth(int n, char s[], int width);

int main(void) {

    int i, width;
    char s[LIMIT];

    i = 25;
    width = 20;

    printf("Initial values:\ni = %d\nwidth = %d\ns = ''\n\n",i,width,s);

    bookitoa(i,s);
    printf("After bookitoa:\ni = %d\nwidth = %d\ns = %s\n\n",i,width,s);

    itoaMinWidth(i,s,width);
    printf("After itoaMinWidth:\ni = %d\nwidth = %d\ns = %s\n\n",i,width,s);


	return 0;

}

void itoaMinWidth(int n, char s[], int width) {

    int i, sign;

    /* get sign, make n positive if necessary */
    if ( (sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0'; // get next digit
    } while ( (n /= 10) > 0);

    // Create string
    if (sign < 0)
        s[i++] = '-';
    while( (i) < width) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}


/* bookitoa: convert n to characters in s. From K&R page 64 */
void bookitoa(int n, char s[]) {

    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {
        s[i++] = n % 10 + '0'; /* get next digit */
    } while (( n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place. From K&R page 62 */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}