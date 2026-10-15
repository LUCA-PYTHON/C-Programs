/*5.1 Lernplan*/
/*Verwenden von switch und case um eingabe schneller zu überprüfen.*/
#include <stdio.h>

int main(void)
{
    int auswahl;

    printf("1 - Addieren\n"
           "2 - Subtrahieren\n"
           "3 - Multiplizieren\n"
           "4 - Dividieren\n"
           "Eingabe: ");

    scanf("%i", &auswahl);

    switch (auswahl)
    {
    case 1:
        printf("Addieren ausgeweahlt");
        break;

    case 2:
        printf("Subtrahieren ausgeweahlt");
        break;

    case 3:
        printf("Multiplizieren ausgeweahlt");
        break;

    case 4:
        printf("Dividieren ausgeweahlt");
        break;
    }
    return 0;
}
