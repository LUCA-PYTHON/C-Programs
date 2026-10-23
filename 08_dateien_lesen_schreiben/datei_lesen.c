/*
 * titel: Dateien lesen
 * nr: 8.1
 * schwierigkeit: 2
 * themen: dateien
 */
#include <stdio.h>

int main(void)
{
    FILE *datei = fopen("database/dateien/lesen.txt", "r");

    if (datei == NULL)
    {
        printf("Datei nicht gefunden");
        return 1;
    }

    char zeile[250];

    while (fgets(zeile, sizeof(zeile), datei) != 0)
    {
        printf("%s", zeile);
    }

    fclose(datei);

    return 0;
}