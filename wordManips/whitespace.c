#include <stdio.h>

main ()
{
	int c, nl, space, tab;

	nl = 0;
	space = 0;
	tab = 0;

	while ((c = getchar ()) != EOF)
	{
		if (c == '\n')
			++nl;
		if (c == '\t')
			++tab;
		if (c == ' ')
			++space;
	}
	printf ("%d Lines %d Tabs %d Spaces\n", nl, tab, space);
}
