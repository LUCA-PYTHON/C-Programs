/*
 * titel: Const und Pointer Taschenrechner
 * nr: 7.3
 * schwierigkeit: 2
 * themen: pointer, const , funktionen, rechnen
 */
#include <stdio.h>

int addieren(const float a, const float b, float *ergebnis)
{
    *ergebnis = a + b;
    return 1;
}

int subtrahieren(const float a, const float b, float *ergebnis)
{
    *ergebnis = a - b;
    return 1;
}

int multiplizieren(const float a, const float b, float *ergebnis)
{
    *ergebnis = a * b;
    return 1;
}

int dividieren(const float a, const float b, float *ergebnis)
{
    *ergebnis = a / b;
    return 1;
}

int main(void)
{
    float a, b, ergebnis;
    char rechenzeichen;
    int erfolg;

    printf("Zahl1: ");
    scanf("%f", &a);

    printf("Zahl2: ");
    scanf("%f", &b);

    printf("Rechenzeichen: ");
    scanf(" %c", &rechenzeichen);

    if (rechenzeichen == '+')
    {
        erfolg = addieren(a, b, &ergebnis);
    }
    else if (rechenzeichen == '-')
    {
        erfolg = subtrahieren(a, b, &ergebnis);
    }
    else if (rechenzeichen == '*')
    {
        erfolg = multiplizieren(a, b, &ergebnis);
    }
    else if (rechenzeichen == '/')
    {
        erfolg = dividieren(a, b, &ergebnis);
    }
    else
    {
        printf("Ungueltiges Rechenzeichen!");
    }

    if (erfolg)
    {
        printf("Ergebnis: %.2f", ergebnis);
    }
    else
    {
        printf("Division durch Null nicht möglich!");
        return 1;
    }

    return 0;
}