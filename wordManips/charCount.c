#include <stdio.h>

int main()
{
	long newCharacter;
	newCharacter = 0;
	while (getchar () != EOF)
		++newCharacter;
	printf ("%ld Characters\n", newCharacter);
	return 0;
}

