#include <stdio.h>

main()
{
	long newCharacter;
	newCharacter = 0;
	while (getchar () != EOF)
		++newCharacter;
	printf ("%ld Characters\n", newCharacter);
}

