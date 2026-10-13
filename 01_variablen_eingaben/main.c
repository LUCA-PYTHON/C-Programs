/*C Lernplan Teil1*/
/*Lernen von Eingabe/Ausgabe und Rechnen mit den Eingaben. Dazu alles sauber und verständlich ausgeben.*/
/*Bei Nenner (Division) Null Fehlermeldung anzeigen.*/
#include <stdio.h>

int main(void)
{

    float zahl1, zahl2;
    char rechenzeichen;

    printf("Zahl 1: ");
    scanf("%f", zahl1);
    printf("Zahl 2: ");
    scanf("%f", zahl2);

    printf("Addition: ", zahl1 + zahl2, "\n");
    printf("Subtraktion: ", zahl1 + zahl2, "\n");
    printf("Multiplikation: ", zahl1 * zahl2, "\n");
    if (zahl2 != 0)
    {
        printf("Division: ", zahl1 / zahl2);
    }
    else
    {
        printf("Error! Kein Nenner mit 0!");
    };
}
