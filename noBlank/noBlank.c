#include <stdio.h>

// move input to output without excess spaces

main ()
{
	int c, prev = 0;

	while ((c = getchar ()) != EOF)
	{
		if (c != ' ' || prev != ' ')
			putchar ( c );
		prev = c;
	}
}

