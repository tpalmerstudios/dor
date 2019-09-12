#include <stdio.h>

// Count lines inputted

main ()
{
	int c, nl;

	nl = 0;
	while ((c = getchar ()) != EOF)
		if (c == '\n')
			++nl;
	printf ("%d Lines\n", nl);
}
