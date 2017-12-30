#include <stdio.h>
#define MAXLENGTH 80 /* print all lines greater than this length */
#define OUTPUTLENGTH 100 /* only print this many characters for any line */

/* Program which prints out all input lines that are longer than 80 characters.
 */

main()
{
    int c, len;
    char line[OUTPUTLENGTH + 1];

    while((c = getchar()) != EOF) {
	if (c == '\n') {
	    if (len > MAXLENGTH) {
		if (len > OUTPUTLENGTH)
		    line[OUTPUTLENGTH] = '\0';
		else
		    line[len] = '\0';
		printf("%s\n", line);
	    }

	    len = 0;
	}
	else {
	    ++len;
	    if (len <= OUTPUTLENGTH) {
		line[len - 1] = c;
	    }
	}
    }

    return 0;
}
