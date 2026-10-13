/*C Lernplan Teil2*/
/*Lernen von Eingabe/Ausgabe und Auswerten der Eingabe. Deutsch mehr IF/ELSE Abfragen.*/
#include <stdio.h>

int main(void)
{
    float zahl;

    printf("Eingabe: ");
    scanf("%f", &zahl);
    printf("\n");

    if (zahl > 0)
    {
        printf("Positive Zahl");
    }
    else if (zahl < 0)
    {
        printf("Negative Zahl");
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
