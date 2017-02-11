/*
 * htoi.c
 *
 *  Created on: Jun 22, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-3
 * Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x
 * or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>
#include <ctype.h>
#define LIMIT 9	/* char spaces needed for a 6 digit HEX number, including possible 0x or 0X */

/* First thoughts
 * This will be a chance to try some casting, and to get used to changing a string to a number.
 */

/* Second thoughts
 * I re-read a lot of chapter 2, and did some more research into data types online, and I need to reconsider
 * this exercise. Just what exactly am I transforming, and how?
 */

/* Third thoughts
 * This is not really about casting, more about data types in general, and formatting in presenting
 * information. I think the actual htoi function will be mostly some math.
 */

int htoi(char s[]);

int main() {
	char s[LIMIT]; /* will hold a hex digit in chars */
	int i, c, hex;

	int hex_intconst;
	int hex_charconst;
	unsigned char hex_string[3];
	int hex_string_intcast;

	hex_intconst = 0x1f;
	hex_charconst = '\x1f';
	hex_string[0] = '1';
	hex_string[1] = 'f';
	hex_string[2] = '\0';
	printf("hex_intconst is: %d\n",hex_intconst);
	printf("hex_intconst is: %x (in hex format)\n",hex_intconst);
	printf("hex_charconst is: %d\n",hex_charconst);
	printf("hex_charconst is: %x (in hex format)\n",hex_charconst);
	printf("hex_string is: %s\n",hex_string);
	hex_string_intcast = (unsigned int)hex_string;
	printf("hex_string casted as int: %d\n",hex_string_intcast);
	putchar('\n');

	i = 0;
	/* while i is less than the length of s[], c is not EOF or newline*/
	while (i<LIMIT-1 && (c=getchar()) != EOF && c!='\n') {
		/* to allow 0x at beginning of string */
		if (s[0] == '0' && i == 1 && (c == 'x' || c == 'X')) {
			s[i] = c;
			++i;
		}
		/* else if c is a valid hex digit */
		else if ((c>='0'&&c<='9') || (c>='a'&&c<='f') || (c>='A'&&c<='F')) {
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';

	printf("char s: %s\n",s);
	printf("char s casted to int: %d\n",(int)s);

	putchar('\n');

	hex = htoi(s);
	printf("htoi in hex format: %x\n",hex);
	printf("htoi in decimal format: %d\n",hex);
	printf("htoi in octal format: %o\n",hex);

	return 0;
}

/* htoi converts a text string of hexidecimal digits to the int value of those digits. works only in
the ASCII character set */
int htoi(char s[]) {

	int i, n, start;

	start = n = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		start = 2;
	for (i=start;i<LIMIT-1;++i) {
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + s[i] - '0'; // '0' is 48 in ASCII, 1-9 follow in order
		if (s[i] >= 'a' && s[i] <= 'f')
			n = n * 16 + s[i] - 'W'; // a is 10 in hex, and 'a' is 97 in ASCII. 'W' is 87, 97-87=10
		if (s[i] >= 'A' && s[i] <= 'F')
			n = n * 16 + s[i] - '7'; // A is 10 in hex, and '7' is 55 in ASCII. 'A' is 65, 65-55=10
	}

	return n;
}
