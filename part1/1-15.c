#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion */
float convert_fahr(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}

main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = convert_fahr(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}