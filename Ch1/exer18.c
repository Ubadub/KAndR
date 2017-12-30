#include <stdio.h>
#define MAXWS 1000 /* maximum number of whitespace characters on a single line */
#define YES 1
#define NO 0

/* Program to remove trailing blanks and tabs and delete any all-whitespace
 * lines from its input (does NOT delete lines which consist exclusively of a
 * newline, which may appear blank visually but of course have a single
 * character)
 */

main()
{
    int whitespace_queue[MAXWS];
    int c, ws_cnt, non_ws_line;

    ws_cnt = non_ws_line = 0;

    while ((c = getchar()) != EOF) {
	if (c == '\n') {
	    if (ws_cnt > 0) { /* trailing whitespace */
		if (non_ws_line) { /* line had at least one non-whitespace character */
		    putchar(c); /* print a new line */
		    non_ws_line = NO;
		}
		
		ws_cnt = 0; /* reset whitespace count */
	    }
	    else /* no trailing whitespace */
		putchar(c); /* print a new line */
	}
	
	else if (c == ' ' || c == '\t') {
	    if (ws_cnt < MAXWS) {
		whitespace_queue[ws_cnt++] = c;
	    }
	}

	else {
	    int i;

	    for (i = ws_cnt; i > 0; i--)
		putchar(whitespace_queue[i - 1]);
	    
	    putchar(c);

	    ws_cnt = 0;
	    non_ws_line = YES;
	}
    }

    return 0;
}
