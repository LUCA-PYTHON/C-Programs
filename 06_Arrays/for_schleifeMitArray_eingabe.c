/*
 * titel: for schleifeMitArray eingabe
 * schwierigkeit: 2
 * themen: arrays, if/else, for-schleife
 */
#include <stdio.h>

int main(void)
{
    float zahlen[100] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100}; // definieren des Arrays (1-100)
    float summe = 0;
    float durchschnitt;
    int anzahl;
    int bigges = zahlen[0];

    printf("Wie viele Zahlen möchtest du im Array: "); // Abfrage wie viele Zahlen man im Array will
    scanf("%i", &anzahl);

    if (anzahl > 100 || anzahl < 1)
    {
        printf("Ungueltige Eingabe!");
        return 0;
    }

    for (int i = 0; i < anzahl; i++)
    {
        printf("Zahl: %.2f\n", zahlen[i]);

        summe = summe + zahlen[i];

        if (bigges < zahlen[i])
        {
            bigges = zahlen[i];
        }
    }

    durchschnitt = summe / anzahl;

    printf("Summe: %.2f\n", summe);
    printf("Durchschnitt: %.2f\n", durchschnitt);
    printf("Groesste Zahl: %i", bigges);

    return 0;
}
