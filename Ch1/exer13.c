#include <stdio.h>

#define MAXWL 20
#define IN    1
#define OUT   0

/* program which prints a histogram of the lengths of words in its input, using
 * horizontal histogram bars.
 */
main()
{
    int wordlengths[MAXWL];
    int len, status, overflow, c, i;

    len = 0;
    status = OUT;
    overflow = 0;

    for (i = 0; i < MAXWL; i++)
	wordlengths[i] = 0;

    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (status == IN) {
		if (len < MAXWL)
		    ++wordlengths[len - 1];
		else
		   ++overflow;
		len = 0;
		status = OUT;
	    }
	}
	else {
	    status = IN;
	    ++len;
	}
    }

   for (i = 0; i < MAXWL; ++i) {
       int j;
       printf("%3i|", i + 1);

       for (j = 0; j < wordlengths[i]; j++)
	   putchar('*');

       putchar('\n');
   }
}
