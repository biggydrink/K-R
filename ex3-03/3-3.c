/*
 * 3-3.c
 *
 *  Created on: Aug 15, 2015
 *      Author: andre_000
 */


/* Exercise 3-3
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into
 * the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and
 * be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
 * - is taken literally.
 */

/* Thoughts:
 * It's 10/22 now, working on this much more sporadically now that I'm in classes. So far I've
 * remembered enough to create the function and have it repeat the string, so the bones are
 * basically in place. Now it's time to code the actual algorithm/steps/function needed to expand
 * string s.
 */

/* Thoughts 10/24:
 * I think this is basically done now. It handles all the cases mentioned in the question, EXCEPT
 * for some reason I can't get a leading - to work. Actually, it looks like it SHOULD work - the
 * control for loop works as expected in debug and the line that adds characters to string t is
 * exactly the same as in all the other cases, but for some reason t just stays as "" instead of
 * being filled with the ascii characters that it loops through. I have no idea why this is, as
 * it even looks like it's working correctly in debug--the code runs and just, nothing happens.
 * So I think I'll look at the answer key and see if I did anything wrong - I'm out of ideas at this
 * point. Maybe if that doesn't reveal anything I'll go to stack overflow.
 */

#include <stdio.h>
#define LIMIT 1000
#define ASCIIEND 127
#define ASCIISTART 0

void expand(char s[], char t[]);

int main(void) {
	int i, c;
	char s[4];
	char t[LIMIT];

	for (i = 0; (c = getchar()) != EOF && i < 4-1; ++i) {
		s[i] = c;
	}
	s[i] = '\0';

	printf("%s\n",s);
	printf("Expanding..\n");
	expand(s,t);
	printf("Expanded string t: \n%s\n",t);
	return 0;

}
/* expand(s,t)
 * Expands characters connected by a '-' in string s to the full range in string t. For example,
 * "a-z" becomes "abc...xyz" in full. Works for any character in the ASCII set, and allows for leading
 * or trailing -'s, although as of right now I can't get leading -'s to work.
 */
void expand(char s[], char t[]) {
	int i, j, k;

	j = 0;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '-') {
			if (i == 0) {
				for (k = ASCIISTART; k < s[i+1]; ++k)
					t[j++] = k;
			} else if (s[i+1] == '\0' || s[i+1] == '\n') {
				for (k = s[i-1] + 1; k < ASCIIEND; ++k)
					t[j++] = k;
			} else if (s[i-1] < s[i+1]) {
				for (k = s[i-1] + 1; k < s[i+1]; ++k)
					t[j++] = k;
			} else if (s[i-1] > s[i+1]) {
				for (k = s[i-1] - 1; k > s[i+1]; --k)
					t[j++] = k;
			}
		} else
			t[j++] = s[i];

	}
	t[j] = '\0';

}
