/*
 * 3-5.c
 *
 *  Created on: Dec 24, 2015
 *      Author: andre_000
 */

/* Exercise 3-5, page 64
 * Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 */

/*
 * Thoughts:
 * Get ready for some math!
 *
 * 2/11/17:
 * Coming back after a long break of Java
 * Is this as simple as changing the n % 10 to n % b?
 *
 * It seems that yes, it is that simple, except that in ASCII there are no non-base10 numbers
 * for the base 10 values of 10-15
 * Normally of course it uses A-F, but the ASCII trick of n + '0' does not work for this, so we'll have to add
 * something in manually. I ended up checking if the result of n % base was higher than '9', and then adding
 * (base - 9) to the result to get at capital letters of the alphabet. This means that the base should be
 * capped at 36, since at that point we run out of letters of the alphabet. (we could therefore change base to a
 * char instead of an int, if we were VERY concerned about memory allocation)
 *
 */


#include <stdio.h>
#include <string.h>

#define LIMIT 100

int itob(int n, char s[], int b);
void bookitoa(int n, char s[]);
void reverse(char s[]);

int main(void) {

    int i, base;
    char s[LIMIT];

    i = 26;
    base = 2;
    printf("Initial values:\ni = %d\ts = ''\n",i);

    bookitoa(i,s);
    printf("After book itoa:\ni = %d\ts = %s\n",i,s);

    if (itob(i,s,base) == -1) {
        printf("Base of %d is too high or too low, itob will not run.",base);
    } else {
        printf("After itob base %d:\ni = %d\ts = %s\n",base,i,s);
    }

    return 0;

}

/* converts a number to a char array (string) of base b
 * base is capped at 36 due to running out of letters in the alphabet */
int itob(int n, char s[], int b) {

    if (b > 36 || b < 2)
        return -1;

    int i, sign, diff;

    diff = b-9;

    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;

    do {
        s[i] = n % b + '0';
        if (s[i] > '9')
            s[i] = s[i] + 7;
        i++;
    } while ( (n /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);

    return 0;

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
