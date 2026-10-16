/*6.0 Lernplan*/
/*Verwenden von Arrays in for schleifen*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int zahlen[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //Array festlegen

    for (int i = 0; i < 10; i++){
        printf("Zahl: %i\n", zahlen[i]);  // [i] gibt an welchen Array wir raus holen wollen
    }

    return 0;
}
