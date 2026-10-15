/*4.0 Funktionen*/
/*Erste kleine Funktion inder 2 Zahlen übergeben werden an die Addieren Funktion und darin mit "return" das Ergebnis zurück an main gesendet wird und ausgegeben.*/
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
