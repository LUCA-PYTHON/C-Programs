/*
 * titel: Erster String: Name einlesen
 * nr: 5.0
 * schwierigkeit: 2
 * themen: strings, fgets, strcspn
 */
#include <stdio.h>
#include <string.h>

int main(void){
    char name[50];

    printf("Dein Name: ");
    fgets(name, sizeof(name), stdin); //Variable, Zeichenlänge (49 eins für \n oder \0), Standarteingabe (Tastatur)

    name[strcspn(name, "\n")] = '\0'; //Entfernt das \n (zeilenumbruch) aus der Eingabe.

    printf("Hallo %s!\n", name);
}
