#include <stdio.h>
#define COLUMNS 8 /* distance between tab stops */

/* This program replaces all tabs in its input with the proper number of space
 * till the next tabstop. Assumes tabstops occur in intervals of 8 columns.
 */

main()
{
    int c, spaces;

    spaces = 0;

    while ((c = getchar()) != EOF) {
	if (c == '\n') {
	    spaces = 0;
	    putchar(c);
	}
	else if (c == '\t') {
	    int i;

	    for (i = 0; i < COLUMNS - spaces; i++)
		putchar(' ');

	    spaces = 0;
	}
	else {
	    if (spaces == COLUMNS - 1)
		spaces = 0;
	    else
		++spaces;

	    putchar(c);
	}
    }

    return 0;
}
