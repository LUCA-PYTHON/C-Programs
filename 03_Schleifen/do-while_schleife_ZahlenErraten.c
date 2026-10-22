/*
 * titel: Zahlenraten-Spiel
 * nr: 3.4
 * schwierigkeit: 2
 * themen: schleifen, do-while, zufall, if/else
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int geheimzahl = rand() % 10 + 1; // zufällige Zahl zwischen 0 und 10
    int eingabe;

    do
    {
        printf("Rate eine Zahl: ");
        scanf("%i", &eingabe);
        if (eingabe > geheimzahl)
        {
            printf("Zu groß!\n");
        }
        else if (eingabe < geheimzahl)
        {
            printf("Zu klein\n");
        }
    } while (eingabe != geheimzahl);

    printf("Richtig erraten. (%i)", geheimzahl);
}
