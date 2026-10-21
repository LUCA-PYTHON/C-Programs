/*
 * titel: void int FunktionUnterschied
 * schwierigkeit: 1
 * themen: funktionen
 */
#include <stdio.h>

int mitRueckgabe(int rückgabe)
{
    return rückgabe + 1;
}

void ohneRueckgabe(){
    printf("Keine Rueckgabe in main.");
}

int main(void)
{
    int rückgabe;

    rückgabe = mitRueckgabe(2);

    printf("Hier siehst du die Rueckgabe: %i\n", rückgabe);

    ohneRueckgabe();
}
