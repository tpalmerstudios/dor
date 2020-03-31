#include <stdio.h>

// Print Fahrenheit to Celsius Conversion table.
// 0 - 300

int main()
{
	float fahr, celsius, kelvin;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahrenheit\tCelsius\t\tKelvin\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		kelvin = celsius + 273.15;
		printf("%6.1f\t\t%3.2f\t\t%4.2f\n", fahr, celsius, kelvin);
		fahr = fahr + step;
	}
	
	printf("\n");
	// Resetting
	// Should look exactly same as the top. May remove for statement after test

	for (fahr=0; fahr <= 300; fahr = fahr + 20)
		printf("%6.1f\t\t%3.2f\t\t%4.2f\n", fahr, (5.0/9.0) * (fahr-32.0), ((5.0/9.0) * (fahr-32.0))+273.15);
}

