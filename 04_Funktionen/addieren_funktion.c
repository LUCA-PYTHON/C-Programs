/*
 * titel: addieren funktion
 * schwierigkeit: 1
 * themen: funktionen, addieren
 */
#include <stdio.h>

int addieren(int a, int b){
    return a + b;
}

int main(void)
{
    int ergebnis;

    ergebnis = addieren(3, 4);  //Aufruf von der Funktion "addieren" mit Zahlen Übergabe

    printf("Ergebnis: %i", ergebnis);
}
