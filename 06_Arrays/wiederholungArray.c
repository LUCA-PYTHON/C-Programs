/*
 * titel: wiederholungArray
 * schwierigkeit: 1
 * themen: arrays, for-schleife, sizeof
 */
#include <stdio.h>

int main(void)
{
    int noten[10] = {1, 2, 3, 4, 5, 2, 3, 4};
    int summe = 0;
    double durchschnitt = 0.0;

    for (int i = 0; i < 10; i++)
    {
        summe = summe + noten[i];
    }

    durchschnitt = (double)summe / (sizeof(noten) / sizeof(noten[0]));

    printf("Summe: %i\n", summe);
    printf("Durchschnitt: %.2f\n", durchschnitt);

    return 0;
}