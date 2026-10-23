/*
 * titel: Dateien beschreiben mit Eingabe/Speicher/Löschen
 * nr: 8.5
 * schwierigkeit: 3
 * themen: dateien, string, while, schleifen
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *datei2 = fopen("database/dateien/schreibenEingabeErweiterung.txt", "r");

    if (datei2 == NULL)
    {
        perror("Fehler beim Öffnen der Datei");
        return 1;
    }

    char zeile[250];

    while (fgets(zeile, sizeof(zeile), datei2) != 0)
    {
        printf("%s", zeile);
    }

    fclose(datei2);

    FILE *datei = fopen("database/dateien/schreibenEingabeErweiterung.txt", "a");

    if (datei == NULL)
    {
        perror("Fehler beim Öffnen der Datei");
        return 1;
    }

    char eingabeListe[250];

    printf("Gib deine Liste ein (Beenden mit ENDE):\n");

    while (fgets(eingabeListe, sizeof(eingabeListe), stdin) != NULL)
    {
        eingabeListe[strcspn(eingabeListe, "\n")] = '\0';

        if (strcmp(eingabeListe, "ENDE") == 0)
        {
            break;
        }
        else if (strcmp(eingabeListe, "DEL") == 0)
        {
            fclose(datei);

            FILE *datei_del = fopen("database/dateien/schreibenEingabeErweiterung.txt", "w");

            if (datei_del == NULL)
            {
                printf("Datei konnte nicht geloescht werden");
                break;
            }

            fclose(datei_del);

            printf("Alle Eintreage geloescht");
            break;
        }

        fprintf(datei, "%s\n", eingabeListe);
    }

    fclose(datei);

    printf("Liste wurde erfolgreich gespeichert.\n");

    return 0;
}