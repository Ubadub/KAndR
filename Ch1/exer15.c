#include <stdio.h>

float fahrToCels(int fahr);

/* Prints a conversion table from Fahrenheit to Celsius for Fahrenheit
 * temperatures of 0, 20, 40, ..., 300. Prints a heading above the table. Uses a
 * function to convert from Fahrenheit to Celsius.
 */
main()
{
    float fahr;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step */

    fahr = lower;
    printf("%s %s\n", "Fahrenheit","Celsius");
    
    while (fahr <= upper) {
	printf("%10.0f %7.1f\n", fahr, fahrToCels(fahr));
	fahr = fahr + step;
    }
}

float fahrToCels(int fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
