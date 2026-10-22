/*
 * titel: Rechteck-Flächenrechner
 * nr: 4.2
 * schwierigkeit: 1
 * themen: funktionen, parameter, float
 */
#include <stdio.h>

float fleacheRechner(float a, float b)
{
    return a * b;
}

int main(void)
{
    float fleache;
    float a, b;

    printf("Eingabe Seite a: ");
    scanf("%f", &a);
    printf("Eingabe Seite B: ");
    scanf("%f", &b);

    fleache = fleacheRechner(a, b);

    printf("Deine Rechteckfleache: %.2f", fleache);
}
