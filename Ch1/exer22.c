#include <stdio.h>
#define MAXLINE 10
#define COL_SIZE 8

void println_up_to(char line[], int start, int end);

/* Program to "fold" lines above a certain length (MAXLINE) into two or more
 * lines. Breaks lines at the last non-blank character before the MAXLINEth
 * column. If there is no whitespace before that column, breaks the line at the
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
     * col counts (from 0 to COL_SIZE) the number of columns since the last
     * tabstop.
     * lastblank indicates the index of the last blank character in the array 
     * line.
     */
    int c, pos, numcols, col, lastblank;
    char line[MAXLINE];
    pos = numcols = col = 0;
    lastblank = -1;

    while ((c = getchar()) != EOF) {
	if (numcols == MAXLINE - 1 || (c == '\t' && (numcols + COL_SIZE - col) == (MAXLINE - 1))) { /* at the boundary */
	    if (c == '\n' || c == ' ' || c == '\t') { /* whitespace, so terminate/fold line */
		println_up_to(line, 0, MAXLINE - 1);
		putchar('\n');

		pos = numcols = col = 0;
		lastblank = -1;
	    }
	    else { /* non whitespace characters, so fold intelligently */
		if (lastblank < 0) { /* no blanks so far in this line */
		    println_up_to(line, 0, MAXLINE - 1);
		    putchar(c);
		    ++pos, ++numcols;

		    if (col == COL_SIZE)
			col = 0;
		    else
			++col;
		}
		else { /* there was a blank earlier, so print up to it */
                    println_up_to(line, 0, lastblank);
		    putchar('\n');
		    /* copy everything past the blank to the beginning */
		    println_up_to(line, lastblank, pos);
		    putchar(c);
		    pos = numcols = col = 0;
		    lastblank = -1;
		}
	    }
	}

	/* past the boundary, which can only happen if the line had no blanks before the boundary */
	else if (numcols >= MAXLINE) {
	    if (c == '\n' || c == ' ' || c == '\t') {
		putchar('\n');
		pos = numcols = col = 0;
		lastblank = -1;
	    }
	    else {
		putchar(c);
		++pos, ++numcols;
		
		if (col == COL_SIZE)
		    col = 0;
		else
		    ++col;
	    }
	}
	else { /* before the boundary */
	    if (c == '\n') {
		println_up_to(line, 0, pos);
		putchar('\n');
		pos = numcols = col = 0;
		lastblank = -1;
	    }
	    else {
                line[pos] = c;
		if (c == ' ' || c == '\t') {
		    lastblank = pos;
		}

		if (c == '\t') {
		    numcols += COL_SIZE - col;
		    col = 0;
		}
		else {
		    if (col == COL_SIZE)
			col = 0;
		    else
			++col;

		    ++numcols;
		}
                pos++;
	    }
	}
    }

return 0;
}

void println_up_to(char line[], int start, int end) {
    int i;

    for (i = start; i < end; ++i)
	putchar(line[i]);
}
