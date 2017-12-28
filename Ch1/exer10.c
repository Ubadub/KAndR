#include <stdio.h>

/* copy input to ouput, replacing tabs, backspaces, and backslashes with their
 * respective escape sequences (\t, \b, and \\).
 */
main()
{
    unsigned c, spaces;

    spaces = 0;
    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    putchar('\\');
	    putchar('t');
	}
	
	else if (c == '\b') {
	    putchar('\\');
	    putchar('b');
	}

	else if (c == '\\') {
	    putchar('\\');
	    putchar('\\');
	}

	else
	    putchar(c);
    }
}
