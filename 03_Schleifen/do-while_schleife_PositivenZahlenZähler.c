/*
 * titel: do-while schleife PositivenZahlenZähler
 * schwierigkeit: 1
 * themen: dp-while-schleife
 */
#include <stdio.h>

int main(void)
{
    char beenden = 'N';
    int zahl;
    int count = 0;

    do
    {
        printf("Zahl eingeben: ");
        scanf("%i", &zahl);

        if (zahl > 0)
        {
            count++;
        }

        printf("Weitere Zahl? (J/N): ");
        scanf(" %c", &beenden); // Leertaste, da sonst das \n erkannt wird anstatt der Eingabe.

    } while (beenden == 'j' || beenden == 'J');

    printf("\nAblauf beendet.\n");
    printf("%i Zahlen positiv.\n", count);

    return 0;
}
