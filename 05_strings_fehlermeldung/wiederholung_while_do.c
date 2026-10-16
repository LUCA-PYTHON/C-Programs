/*5.3 Lernplan*/
/*Wiederholung, baue eine Eingabe, die sich ständig wiederholt. Bis man "/beenden" eingeben.*/
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
