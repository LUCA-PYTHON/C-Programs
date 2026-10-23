/*
 * titel: JSON Dateien beschreiben
 * nr: 8.3
 * schwierigkeit: 2
 * themen: dateien, json
 */
#include <stdio.h>

int main(void)
{
    FILE *datei = fopen("database/dateien/schreibenListe.json", "w");

    if (datei == NULL)
    {
        printf("Datei nicht gefunden");
        return 1;
    }

    fprintf(datei, "[\n");
    fprintf(datei, "    \"Teil1\",\n");
    fprintf(datei, "    \"Teil2\",\n");
    fprintf(datei, "    \"Teil3\"\n");
    fprintf(datei, "]\n");

    fclose(datei);

    printf("Datei wurde erfolgreich beschrieben");

    return 0;
}