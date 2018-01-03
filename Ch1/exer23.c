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
	    if (star) { /* end of comment (cannot be in quotes b/c star flag never set when in quotes) */
		incomment = NO;
		fslash = NO;
		star = NO;
	    }
	    else if (!incomment) { /* slashes inside comments are disregarded */
		if (!fslash && !indbquotes) { /* not in string literal; might be start of comment */
		    fslash = YES;
		}	

		/* slashes in double quotes (i.e. in string literals) are simply printed, or slash after slash  */
		else {
		    fslash = !indbquotes; /* only set fslash flag if we are not in quotes, otherwise disable */
		    putchar(c);
		}
	    }

	    bslash = NO;
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
	    
	    bslash = NO;
	}
	else if (!incomment) { /* not in a comment and current char not a * or / */
	    if (fslash) {
		putchar('/');
	    }
	    if (star) {
		putchar('*');
	    }

	    if (c == '\\' && (insngquotes || indbquotes)) {
		bslash = !bslash;
	    }
	    else {
		if (c == '\'' && !indbquotes && !bslash)
		    insngquotes = !insngquotes;

		else if (c == '"' && !insngquotes && !bslash) {
		    indbquotes = !indbquotes;
		}
		fslash = bslash = star = NO;
	    }
	    
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
