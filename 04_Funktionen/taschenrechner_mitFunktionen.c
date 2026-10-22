/*
 * titel: Taschenrechner mit Funktionen
 * nr: 4.4
 * schwierigkeit: 2
 * themen: funktionen, rechnen, if/else
 */
#include <stdio.h>

float addieren(float zahl1, float zahl2)
{
    return zahl1 + zahl2;
}

float subtrahieren(float zahl1, float zahl2)
{
    return zahl1 - zahl2;
}

float multiplizieren(float zahl1, float zahl2)
{
    return zahl1 * zahl2;
}

float dividieren(float zahl1, float zahl2)
{
    return zahl1 / zahl2;
}

int main(void)
{
    float zahl1;
    float zahl2;
    float ergebnis;
    char rechenzeichen;

    printf("Zahl1: ");
    scanf("%f", &zahl1);

    printf("Zahl2: ");
    scanf("%f", &zahl2);

    printf("Rechenzeichen: ");
    scanf(" %c", &rechenzeichen);

    if (rechenzeichen == '-')
    {
        ergebnis = subtrahieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '+')
    {
        ergebnis = addieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '*')
    {
        ergebnis = multiplizieren(zahl1, zahl2);
    }
    else if (rechenzeichen == '/')
    {

        if (zahl2 == 0)
        {
            printf("Nenner darf nicht Null sein!");
            return 1;
        }
        ergebnis = dividieren(zahl1, zahl2);
    }
    else
    {
        printf("Ungültiges Rechenzeichen (+, -, *, /)");
    }

    printf("Ergebnis: %.2f", ergebnis);
}
