#include <stdio.h>

// Count characters inputted
// v1

main()
{
	long nc;
	nc = 0;
	while (getchar () != EOF)
		++nc;
	printf ("%ld Characters\n", nc);
}

