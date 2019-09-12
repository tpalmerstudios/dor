#include <stdio.h>

// move input to output showing escape characters

main ()
{
	int c = 0;

	while ((c = getchar ()) != EOF)
	{
		switch ( c )
		{
			case '\t':
				printf ("\\t");
				break;
			case '\b':
				printf ("\\b");
				break;
			case '\\':
				printf ("\\\\");
				break;
			default:
				putchar ( c );
		}
	}
}

