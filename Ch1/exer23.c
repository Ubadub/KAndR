#include <stdio.h>
#define YES 1
#define NO 0

/* This program removes C89/C90 style comments from its input */

main()
{
    int c, incomment, insngquotes, indbquotes, fslash, bslash, star;
    
    incomment = insngquotes = indbquotes = fslash = bslash = star = NO;

    while ((c = getchar()) != EOF) {
	if (c == '/') {
	    if (star) { /* end of comment */
		incomment = NO;
		fslash = NO;
		star = NO;
	    }
	    else if (!incomment) { /* slashes inside comments are disregarded */
		if (!fslash) { /* might be start of comment */
		    fslash = YES;
		}

		else { /* slash after slash, so we print one slash (the other might be printed later */
		    putchar(c);
		}
	    }
	}
	else if (c == '*') {
	    if (incomment) { /* might be end of comment */
		star = YES;
	    }
	    else if (fslash) { /* start of comment */
		incomment = YES;
	    }
	    else /* not in comment and not preceded by slash */
		putchar(c);
	}
	else if (!incomment) { /* not in a comment and current char not a * or / */
	    if (fslash) {
		putchar('/');
	    }
	    if (star) {
		putchar('*');
	    }

	    if (c == '\'' && !indbquotes)
		insngquotes = !insngquotes;
	    
	    else if (c == '"') {
		indbquotes = !indbquotes;
	    }
	    fslash = star = NO;
	    putchar(c);
	}
	else if (incomment) { /* in a comment, but not at a * or /, so reset flags */
	    star = fslash = NO;
	}
    }

    if (incomment) /* reached end of input but still inside a comment */
	printf("Unclosed comment!\n");

    return 0;
}
