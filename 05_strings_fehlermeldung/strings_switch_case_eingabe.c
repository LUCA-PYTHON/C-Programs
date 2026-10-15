/*5.2 Lernplan*/
/*Switch Case abfrage welchen string man eingebene hat. (Mittel Schwer)*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char auswahl[30];
    int menuepunkt = 0;

    // Menü anzeigen
    printf("/addieren\n");
    printf("/subtrahieren\n");
    printf("/multiplizieren\n");
    printf("/dividieren\n");
    printf("Eingabe: ");

    // Eingabe einlesen und prüfen, ob sie erfolgreich war
    if (fgets(auswahl, sizeof(auswahl), stdin) == NULL)
    {
        printf("Eingabefehler!\n");
        return 1;
    }

    // Zeilenumbruch aus der Eingabe entfernen
    auswahl[strcspn(auswahl, "\n")] = '\0';

    // Eingabe mit den verfügbaren Befehlen vergleichen
    // strcmp() liefert 0, wenn beide Zeichenketten identisch sind
    if (strcmp(auswahl, "/addieren") == 0)
        menuepunkt = 1;
    else if (strcmp(auswahl, "/subtrahieren") == 0)
        menuepunkt = 2;
    else if (strcmp(auswahl, "/multiplizieren") == 0)
        menuepunkt = 3;
    else if (strcmp(auswahl, "/dividieren") == 0)
        menuepunkt = 4;

    // Je nach Menuepunkt den passenden Programmteil ausführen
    // switch prüft hier eine Zahl, da C keine Strings direkt vergleichen kann
    switch (menuepunkt)
    {
    case 1:
        printf("Addieren ausgewaehlt\n");
        break;

    case 2:
        printf("Subtrahieren ausgewaehlt\n");
        break;

    case 3:
        printf("Multiplizieren ausgewaehlt\n");
        break;

    case 4:
        printf("Dividieren ausgewaehlt\n");
        break;

    default:
        printf("Ungueltige Auswahl!\n");
        break;
    }

    return 0;
}
