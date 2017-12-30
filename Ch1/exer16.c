#include <stdio.h>
#define MAXLINE 10

/* Modification of the program from section 1.9. Prints the longest line in the
 * input (to 1000 characters) and then prints the length of that line. */

int getline(char line[], int maxline);
void copy(char to[], char from[], int tosize);

main()
{
    int len;			/* current line length */
    int max;			/* maximum length seen so far */
    char line[MAXLINE];		/* current input line */
    char longest[MAXLINE]; 	/* longest line saved here */

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
	if (len > max) {
	    max = len;
	    copy(longest, line, MAXLINE);
	}

    if (max > 0) /* there was a line */
	printf("Longest line, %i characters: %s\n", max, longest);

    return 0;
    
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    
    while((c = getchar()) != EOF && c != '\n') {
	if (i < lim - 1) /* because final character is a newline */
	    s[i] = c;
	
	i++;
    }

    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[], int tosize)
{
    int i;

    for(i = 0; i < tosize; i++)
	to[i] = from[i];
}
