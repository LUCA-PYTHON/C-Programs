/*
titel: 02_Bedienungen
beschreibung: if/else Verwendung und Umwandlung von float in int.
level: 1
themen: rechnen, if/else, datentypen umwandeln
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
