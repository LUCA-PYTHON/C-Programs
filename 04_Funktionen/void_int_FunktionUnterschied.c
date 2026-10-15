/*4.2 Lernplan*/
/*unterschied "int" Funktion und "void" Funktion.
Mithilfe von int/float/... kann man Werte zurückgeben. 
Bei einer void Funktion wird nur etwas ausgeführt und nichts zurück gegeben.*/
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
