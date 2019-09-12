#include <stdio.h>
#include <ctype.h>

#define IN 1 //inside a word
#define OUT 0 //outside a word
#define GRAPHSIZE 25 //how many words are to be displayed
#define WORDSIZE 25 //how many letters per word are allowed

int main ()
{
	int c, nw, state, currentWord, i, j, k, row, column;
	int wordLength [ GRAPHSIZE ] = {0};
	char words [ GRAPHSIZE ] [ WORDSIZE + 1] = {0};
	state = OUT;
	for (i = 0; i < GRAPHSIZE; i++)
	{
		for (j = 0; j < WORDSIZE; j++)
			words [j][i] = ' ';
	}
	i = k = nw = currentWord = 0;
	// Continue to get characters until "Ctrl-D" is pressed. (Or some other end to input)
	while (((c = getchar ()) != EOF) && nw < GRAPHSIZE)
	{
		// "'" and "-" in hyuphenated or contracted words are also included. 
		// No other punctuation will be unless there is a change I see needed
		if ( isalpha ( c ) || ((c == '\'') || (c == '-')))
		{
			words [i][currentWord] = c;
			++currentWord;
			if (state == OUT)
				++nw;
			state = IN;
		}
		else
		{
			if ((i < GRAPHSIZE))
				wordLength [ i ] = currentWord;
			if (state == IN)
				++i;
			state = OUT;
			currentWord = 0;
		}
	}
	printf ("\nWord Length Graph\n");
	printf ("-----------------\n");
	printf ("Total Words: %d\n", nw);
	printf ("Max Words: %d\n", GRAPHSIZE);

	for (row = 0; row < GRAPHSIZE; row++)
	{
		printf ("\n%2d|%25s|", row + 1, words [row]);
		for (column = 0; (column < wordLength [row]); column++)
			printf("*");
			
	}
	printf ("\n");
	return 0;
}

