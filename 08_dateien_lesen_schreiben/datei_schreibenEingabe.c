#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *datei = fopen("database/dateien/schreibenEingabe.txt", "w");

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

        fprintf(datei, "%s\n", eingabeListe);
    }

    fclose(datei);

    printf("Liste wurde erfolgreich gespeichert.\n");

    return 0;
}