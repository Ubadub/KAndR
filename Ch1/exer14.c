#include <stdio.h>
#include <limits.h>
#include <ctype.h>

#define IN    1
#define OUT   0

/* program which prints a histogram of the frequencies of different characters
 * in its input, using horizontal bars (does not tabulate control characters,
 * i.e. carriage return, file seperators, etc., with the exception of tabs 
 * and newlines.)
 */
main()
{
    size_t charfreqs[UCHAR_MAX];
    unsigned c, i;

    for (i = 0; i < UCHAR_MAX; i++)
	charfreqs[i] = 0;

    while ((c = getchar()) != EOF) {
	if (c < UCHAR_MAX && (isprint(c) || c == '\t' || c == '\n'))
	    ++charfreqs[c];
    }
    
    for (i = 0; i < UCHAR_MAX; ++i) {
	int cnt, j;
	cnt = charfreqs[i];

        if (cnt > 0) {
	    if (i == '\n') 
		printf("%7s", "\\n");
	    else if (i == '\t')
		printf("%7s", "\\t");
	    else if (i == ' ')
		printf("(space)");
	    else
		printf("%7c", i);

	    printf(" | ");

	    for (j = 0; j < cnt; j++)
		putchar('*');
	    
	    putchar('\n');
	}
    }
}
