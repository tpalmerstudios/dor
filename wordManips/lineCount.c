#include <stdio.h>

int main ()
{
	int c;
	int nl = 0;

	while ((c = getchar ()) != EOF)
		if (c == '\n')
			++nl;
	printf ("%d Lines: ", nl);
	return 0;
}
