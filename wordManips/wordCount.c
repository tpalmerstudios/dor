#include <stdio.h>

#define IN 1 //inside a word
#define OUT 0 //outside a word

// count lines, words, and chars inputted

int main ()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar ()) != EOF)
	{
		++nc;
		
		if (c == '\n')
			++nl;
		if (c == '\n' || c == ' ' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf ("%d Lines\n%d Words\n%d Characters\n", nl, nw, nc);
	return 0;
}

