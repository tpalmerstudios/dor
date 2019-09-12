#include <stdio.h>

// move input to output

main ()
{
	int c;

	c = getchar();
	while ((c = getchar ()) != EOF)
		putchar ( c );
}

