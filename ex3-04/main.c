/*
 * 3-4.c
 *
 *  Created on: Dec 24, 2015
 *      Author: andre_000
 */

/*
 * K&R Exercise 3-4, page 64
 * In a two's complement number representation, our version of itoa does not handle the largest
 * negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify
 * it to print that value correctly, regardless of the machine on which it runs.
 */

/*
 * Thoughts:
 * It's now 12/24/15, classes ended last week. It'll be good to catch up on C a little. This
 * one seems like I'll have to look up two's complement again, and study itoa and maybe atoi.
 */

/*
 * Thoughts 12/28:
 * I had to read up on two's complement, but it seems to me that the reason it doesn't work for the largest negative number
 * is that the largest number represented is always negative because of how the first bit (the sign bit) is always 1 in a negative number.
 * So for an 8 bit number, 127 is 0111-1111. But adding 1, which would be 128 (127 + 1), is 1000-0000, which is actually -128 in twos
 * complement. So the line "n = -n" to make n positive will not work with the largest negative number, whatever it is.
 *
 * As for my solution, I wouldn't call it elegant, but it works. I noticed that when n is the largest possible negative number,
 * n = -n does nothing, so n still == n. So I checked for that by seeing if sign == n, then incrementing n by 1 (effectively making it
 * one less than the largest negative number), and then making n = -n. I also added a variable to track whether this occurred. From
 * there we just add a step in the loop to add 1 to the first digit (ones digit) if this is the case. Not elegant, but it worked.
 * Note: I checked all this by using char, where the largest possible negative number is -128.
 *
 * The book solution sets up an abs() macro at the beginning of the program, does not do n = -n, and then changes the loop command
 * from "n % 10 + '0'" to "abs(n % 10) + '0'". As someone who hasn't taken any high level math, I realized that modulus did not work
 * with negative numbers (that was my first attempt), but I didn't know that abs(n % 10) WOULD work. Anyway, the only other change is
 * that the loop check at the end becomes "(n /= 10) != 0)" since n can still be a negative number.
 */

#include <stdio.h>
#include <string.h>

#define LIMIT 100

void bookitoa(char n, char s[]);
void itoa(char n, char s[]);
void reverse(char s[]);

int main(void) {
	char c, newc;
	char s[LIMIT];
	char news[LIMIT];

	c = -128;

	newc = c;

	bookitoa(c,s);
	printf("Bookitoa:\nint: %d\tchar array: %s\n",c,s);

	itoa(newc,news);
	printf("itoa:\nint: %d\tchar array: %s\n",newc,news);

	return 0;

}

/* itoa: convert n to characters in s. Works with highest negative number. */
void itoa(char n, char s[]) {

	int i, sign;
	int check;

	if ((sign = n) < 0) {		/* record sign */
		n = -n;				/* make n positive */
		if (sign == n) {
			++n;
			n = -n;
			check = 1;
		}
	}
	i = 0;
	do {	/* generate digits in reverse order */
		s[i] = n % 10 + '0';	/* get next digit */
		if (i == 0 && check == 1)
			s[i] = s[i] + 1;
		++i;
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* bookitoa: convert n to characters in s. From K&R page 64 */
void bookitoa(char n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)		/* record sign */
		n = -n;				/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);
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
