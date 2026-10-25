/*
 * titel: Dateien Verkünpfen
 * schwierigkeit: 2
 * themen: strukturen, debbuging
 */

#include <stdio.h>
#include "rechnen.h"

int main(void)
{
    int zahl1, zahl2, ergebnis;
    char rechenzeichen;

    printf("Eingabe Zahl1: ");
    scanf("%i", &zahl1);

    printf("Eingabe Zahl2: ");
    scanf("%i", &zahl2);

    printf("Rechenzeichen: ");
    scanf(" %c", &rechenzeichen);

    if (rechenzeichen == '+')
    {
        ergebnis = addieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '-')
    {
        ergebnis = subtrahieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '*')
    {
        ergebnis = multiplizieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '/')
    {
        if (zahl2 != 0)
        {
            ergebnis = dividieren(zahl1, zahl2);
        }
        else
        {
            printf("Fehler Division.");
            return 1;
        }
    }
    else
    {
        printf("Ungültige Eingabe");
        return 1;
    }

    printf("Ergebnis: %i", ergebnis);
    return 0;
}