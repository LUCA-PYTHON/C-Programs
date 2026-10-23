/*
 * titel: Dateien beschreiben
 * nr: 8.0
 * schwierigkeit: 2
 * themen: dateien
 */
#include <stdio.h>

int main(void)
{
    FILE *datei = fopen("database/dateien/test.txt", "w");

    if (datei == NULL)
    {
        printf("Datei nicht gefunden.");
        return 1;
    }

    fprintf(datei, "Hallo Welt!\n");
    fprintf(datei, "Hier lernen wir C programmieren.");
    fclose(datei);

    printf("Datei wurde erfolgreich beschrieben.");
    return 0;
}