#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char s[]);

main()
{
    char line[MAXLINE];
    int len, i;

    while ((len = getline(line, MAXLINE)) > 0) {
	reverse(line);
	for (i = 0; i < len; i++)
	    putchar(line[i]);

    }

    putchar('\n');
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

	++i;
    }

    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
    unsigned i, j, len;
    unsigned char temp;

    len = 0;

    while (s[len] != '\0') {
	++len;
    }

    j = len - 1;
    for (i = 0; i < j; ++i, --j) {
	temp = s[j];
	s[j] = s[i];
	s[i] = temp;
    }
}
