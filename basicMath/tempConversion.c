#include <stdio.h>

// Print Fahrenheit to Celsius Conversion table.
// 0 - 300

int main()
{
	float celsius, kelvin;
	int lower = 0;
	int upper = 300;
	int step = 20;
	float fahr = lower;

	printf("Fahrenheit\tCelsius\t\tKelvin\n");

	for (fahr=0; fahr <= 300; fahr = fahr + 20)
		printf("%6.1f\t\t%3.2f\t\t%4.2f\n", fahr, (5.0/9.0) * (fahr-32.0), ((5.0/9.0) * (fahr-32.0))+273.15);
/*	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		kelvin = celsius + 273.15;
		printf("%6.1f\t\t%3.2f\t\t%4.2f\n", fahr, celsius, kelvin);
		fahr = fahr + step;
	}
	These lines do the exact same as above
*/	
	return 0;
}

