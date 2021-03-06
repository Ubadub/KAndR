#include <stdio.h>

/* Prints a conversion table from Fahrenheit to Celsius for Fahrenheit
 * temperatures of 0, 20, 40, ..., 300. Prints a heading above the table
 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step */

    fahr = lower;
    printf("%s %s\n", "Fahrenheit","Celsius");
    
    while (fahr <= upper) {
	celsius = (5.0/9.0) * (fahr - 32.0);
	printf("%10.0f %7.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
}
