#include <stdio.h>

// move input to output

int main ()
{
	int c;

	c = getchar();
	while ((c = getchar ()) != EOF)
		putchar ( c );
	return 0;
}

