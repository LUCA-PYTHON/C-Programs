/*
 * titel: Zahl analysieren (positiv, negativ, gerade)
 * nr: 2.0
 * schwierigkeit: 1
 * themen: if/else, modulo, typumwandlung
 */
#include <stdio.h>

int main(void)
{
    float zahl;

    printf("Eingabe: ");
    scanf("%f", &zahl);
    printf("\n");

    int ganzzahl = (int)zahl; //Umwandeln von float in int (Modulo)

    if (zahl > 0)
    {
        printf("Positive Zahl\n");
        if (ganzzahl % 2 == 0)
        {
            printf("Gerade Zahl");
        }
        else if (ganzzahl % 2 != 0)
        {
            printf("Ungerade Zahl");
        }
    }
    else if (zahl < 0)
    {
        printf("Negative Zahl\n");
        if (ganzzahl % 2 == 0)
        {
            printf("Gerade Zahl");
        }
        else if (ganzzahl % 2 != 0)
        {
            printf("Ungerade Zahl");
        }
    }
    else if (zahl == 0)
    {
        printf("Zahl ist Null");
    }
    else
    {
        printf("Error");
    };
}
