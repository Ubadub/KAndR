#include <stdio.h>

/* copy input to ouput, replacing any sequences of multiple spaces with a single
 * space */
main()
{
    unsigned c, spaces;

    spaces = 0;
    while ((c = getchar()) != EOF) {
	if (c == ' ') {
	    if (spaces == 0) {
		spaces = 1;
		putchar(c);
	    }
	}
	else {
	    spaces = 0;
	    putchar(c);
	}
    }
}
