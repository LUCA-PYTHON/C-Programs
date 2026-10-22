/*
 * titel: Rechnen mit Eingaben
 * nr: 1.0
 * schwierigkeit: 1
 * themen: variablen, eingabe, ausgabe, rechnen
 */
#include <stdio.h>

int main(void)
{

    float zahl1, zahl2;
    char rechenzeichen;

    printf("Zahl 1: ");
    scanf("%f", &zahl1);
    printf("Zahl 2: ");
    scanf("%f", &zahl2);

    printf("Addition: %.2f\n", zahl1 + zahl2);
    printf("Subtraktion: %.2f\n", zahl1 - zahl2);
    printf("Multiplikation: %.2f\n", zahl1 * zahl2);
    if (zahl2 != 0)
    {
        printf("Division: %.2f", zahl1 / zahl2);
    }
    else
    {
        printf("Error! Kein Nenner mit 0!");
    };
}
