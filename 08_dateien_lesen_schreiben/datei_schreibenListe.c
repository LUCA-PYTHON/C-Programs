/*
 * titel: Listen in Datei schreiben
 * nr: 8.2
 * schwierigkeit: 2
 * themen: dateien, arrays
 */

#include <stdio.h>

int main(void)
{
    const char *liste[] = {
        "Teil1",
        "Teil2",
        "Teil3"
    };

    int anzahl = sizeof(liste) / sizeof(liste[0]);

    FILE *datei = fopen("database/dateien/schreibenListe.txt", "w");

    if (datei == NULL)
    {
        perror("Fehler beim Öffnen der Datei");
        return 1;
    }

    for (int i = 0; i < anzahl; i++)
    {
        fprintf(datei, "%s\n", liste[i]);
    }

    fclose(datei);

    printf("Datei wurde erfolgreich beschrieben.\n");

    return 0;
}