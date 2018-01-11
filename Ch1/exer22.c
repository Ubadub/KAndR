#include <stdio.h>
#define MAXLINE 10
#define MAXCOLUMNS 8

void println_up_to(char line[], int lim);

/* Program to "fold" lines above a certain length (80 columns) into two or more
 * lines. Breaks lines at the last non-blank character before the 80th column.
 * If there is no whitespace before the 80th column, breaks the line at the
 * furthest left (i.e. earliest encountered) blank. If there are no blanks in
 * the entire line, prints the entire line as-is.
 */
main()
{
    /* c is the current character
     * pos is the position within the array line, i.e., the number of characters
     * in the line.
     * numcols counts the number of columns (accounting for the behavior of
     * tabs).
     * col counts (from 0 to MAXCOLUMNS) the number of columns since the last
     * tabstop.
     * lastblank indicates the index of the last blank character in the array 
     * line.
     */
    int c, pos, numcols, col, lastblank;
    char line[MAXLINE];
    numcols = col = 0;
    pos = lastblank = -1;

    while ((c = getchar()) != EOF) {
	if (numcols == MAXLINE - 1 || (c == '\t' && (numcols + MAXCOLUMNS - col) == (MAXLINE - 1))) { /* at the boundary */
	    if (c == '\n' || c == ' ' || c == '\t') { /* whitespace, so terminate/fold line */
		println_up_to(line, MAXLINE - 1);
		putchar('\n');

		numcols = col = 0;
		pos = lastblank = -1;
	    }
	    else { /* non whitespace characters, so fold intelligently */
		if (lastblank < 0) { /* no blanks so far in this line */
		    println_up_to(line, MAXLINE - 1);
		    putchar(c);
		    ++pos, ++numcols;

		    if (col == MAXCOLUMNS)
			col = 0;
		    else
			++col;
		}
		else { /* there was a blank earlier, so print up to it */
		    println_up_to(line, lastblank);
		    putchar('\n');
		    putchar(c);
		    numcols = col = 0;
		    pos = lastblank = -1;
		}
	    }
	}

	/* past the boundary, which can only happen if the line had no blanks before the boundary */
	else if (numcols >= MAXLINE) {
	    if (c == '\n' || c == ' ' || c == '\t') {
		putchar('\n');
		numcols = col = 0;
		pos = lastblank = -1;
	    }
	    else {
		putchar(c);
		++pos, ++numcols;
		
		if (col == MAXCOLUMNS)
		    col = 0;
		else
		    ++col;
	    }
	}
	else { /* before the boundary */
	    ++pos;
	    if (c == '\n') {
		println_up_to(line, pos);
		putchar('\n');
		numcols = col = 0;
		pos = lastblank = -1;
	    }
	    else {
		line[pos] = c;
		if (c == ' ' || c == '\t') {
		    lastblank = pos;
		}

		if (c == '\t') {
		    numcols += MAXCOLUMNS - col;
		    col = 0;
		}
		else {
		    if (col == MAXCOLUMNS)
			col = 0;
		    else
			++col;

		    ++numcols;
		}
	    }
	}
    }

return 0;
}

void println_up_to(char line[], int lim) {
    int i;

    for (i = 0; i < lim; ++i)
	putchar(line[i]);
}
