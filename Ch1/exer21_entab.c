#include <stdio.h>
#define COLUMNS 8 /* distance between tab stops */

void print_whitespace(int whitespace, int col);

/* This program replaces strings of blanks in its input with the minimum number
 * of tabs and spaces needed to achieve the same spacing. When either a single
 * tab or a single tab can reach the next tab stop, the program uses the tab.
 */

main()
{
    /* col counts, from 0 to 7, the current column of the cursor.
     * whitespace counts the total amount of whitespace columns since the last
     * tabstop.
     * tabstops counts the total number of tabstops passed since the last
     * non-whitespace column.
     */
    int c, col, whitespace, tabstops;

    col = whitespace = tabstops = 0;

    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    whitespace += COLUMNS - col;
	    col = 0;
	    ++tabstops;
	}

	else if (c == ' ') {
	    ++whitespace;

	    if (col == COLUMNS - 1) {
		col = 0;
		++tabstops;
	    }
	    else
		++col;
	}

	else {
	    if (whitespace == 0) {
		if (col == COLUMNS - 1) {
		    col = 0;
		    ++tabstops;
		}
		else
		    ++col;
	    }
	    else
		print_whitespace(whitespace, col);

	    if (c == '\n') {
		col = 0;
		tabstops = 0;
	    }

	    whitespace = 0;
	    
	    putchar(c);
	}
    }

    return 0;
}

/* Prints the appropriate amount of whitespace.
 *
 * whitespace indicates the total number of whitespace columns that must be
 * printed.
 *
 * col (from 1 to 7) indicates the distance since the last col
 */
void print_whitespace(int whitespace, int col) {
    int i, numspaces, numtabs;

    if (whitespace > col) { /* at least one tabstop passed */
	/* printf("true, col: %i, whitespace: %i\n", col, whitespace); */
	putchar('\t');
	whitespace -= COLUMNS - col;
    }

    numtabs = whitespace / COLUMNS;
    numspaces = whitespace % COLUMNS;

    for (i = 0; i < numtabs; ++i) {
	putchar('\t');
    }

    for (i = 0; i < numspaces; ++i)
	putchar(' ');
}
