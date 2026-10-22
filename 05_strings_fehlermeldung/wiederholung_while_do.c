/*
 * titel: Eingabeschleife bis /beenden
 * nr: 5.3
 * schwierigkeit: 2
 * themen: strings, do-while, strcmp, fgets
 */
#include <stdio.h>
#include <string.h>

int main(void)
{

    char eingabe[50];

    do
    {
        printf("Eingabe: ");
        fgets(eingabe, sizeof(eingabe), stdin); // string auslesen

        eingabe[strcspn(eingabe, "\n")] = '\0'; //Zeilenumbruch entfernen

    } while (strcmp(eingabe, "/beenden") != 0); //Wenn eingabe "/beenden" schleife beenden

    printf("Eingabe wurde beendet!");

    return 0;
}
