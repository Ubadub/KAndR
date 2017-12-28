#include <stdio.h>

/* count blanks, tabs, and newlines in input */
main()
{
    int c, blanks, tabs, newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while((c = getchar()) != EOF) {
	if (c == ' ')
	    ++blanks;
	
	if (c == '\t')
	    ++tabs;

	if (c == '\n')
	    ++newlines;
    }

    printf("The number of blanks was %i, the number of tabs was %i, the number of newlines was %i\n", blanks, tabs, newlines); 
}
