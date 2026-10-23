/*
 * titel: Pointer Übung
 * nr: 7.2
 * schwierigkeit: 3
 * themen: pointer, variablen
 */
#include <stdio.h>

/*
*a --> Adresse
a  --> Zahl
*/

int main(void)
{
    int a = 1, b = 2, c = 3;

    int *z = &a;
    int *y = &b;
    int *x = &c;

    printf("Ausgangszahlen\n");
    printf("a = %i, b = %i, c = %i\n", a, b, c);
    printf("x = %p, y = %p, x = %p\n\n", (void *)x, (void *)y, (void *)z);

    int *temp = z;
    z = y;
    y = x;
    x = temp;

    printf("Adressen verdreht\n");
    printf("a = %i, b = %i, c = %i\n", a, b, c);
    printf("x = %p, y = %p, x = %p\n\n", (void *)x, (void *)y, (void *)z);

    int ptemp = *z;
    *z = *y;
    *y = *x;
    *x = ptemp;

    printf("Zahlen verdrehen\n");
    printf("a = %i, b = %i, c = %i\n", a, b, c);
    printf("x = %p, y = %p, x = %p", (void *)x, (void *)y, (void *)z);
}