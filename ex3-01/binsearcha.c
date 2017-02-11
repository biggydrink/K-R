/*
 * binsearch.c
 *
 *  Created on: Jul 15, 2015
 *      Author: andre_000
 */

/* K&R Exercise 3-10, 7/15/15
 * Our binary search makes two tests inside the loop, when one would suffice (at the price of more
 * tests outside). Write a version with only one test inside the loop and measure the difference
 * in run-time.
 */

/* First thoughts, 7/15/15
 * The book's binsearch() function is so logical that I'm having a hard time thinking of what test
 * to take out of the loop - I suppose either take either the higher or lower check out, or else
 * make it into a very weak search function that has to check every number (if x != v[y] then y-1, loop).
 *
 * The other hiccup I see coming is that I'm not sure how to measure run-time, but I'm sure I can find
 * something online to help with that.
 */

/* Second thoughts, 7/16/15
 * My solution to the program worked, but I couldn't find an easy way to see the run-time (execution time)
 * except if I was using Ubuntu, which I'm not. I ended up looking at the answer book, which gave a
 * solution with a similar while loop, except that another check of x != v[mid]. Thus the program
 * ends when either low = high (i.e. the entirity of v[] has been searched) or x = v[mid]. The final
 * check is performed after the while loop, where either x is v[mid] and x is returned, or it is not
 * and then -1 is returned. Having to perform this final check only once (so says the book) makes the
 * operation marginally faster, but since the code is less readable the book advises against it.
 */

#include <stdio.h>
#define LIMIT 101

int bookbinsearch(int x, int v[], int n);
int search(int x, int v[], int n);

int main(void) {
	int x;
	int v[LIMIT];
	int book_solution; /* search solution with the bookbinsearch function */
	int my_solution; /* search solution with the search function */

	for (x = 0; x<LIMIT; ++x)
		v[x] = x;

	x = 23;

	book_solution = bookbinsearch(x, v, LIMIT);
	my_solution = search(x, v, LIMIT);

	printf("Book solution: %d\n",book_solution);
	printf("My solution: %d\n",my_solution);

	return 0;
}

int search(int x, int v[], int n) {
	int high, answer;

	high = n-1;
	for (answer = high; answer > 0; --answer) {
		if (x == v[answer])
			return answer;
	}
	return -1; /* no match */
}

int bookbinsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n-1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid-1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1; /* no match */
}
