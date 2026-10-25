#include "modul.h"
#include <stdio.h>
#include <string.h>

void anzeigen(const struct lager artikel[], int anzahl)
{
    if (anzahl == 0)
    {
        printf("Keine Artikel vorhanden.\n");
        return;
    }

    for (int i = 0; i < anzahl; i++)
    {
        printf("\nArtikelnummer: %d\n", artikel[i].artikelnummer);
        printf("Name: %s\n", artikel[i].artikel);
        printf("Preis: %.2f Euro\n", artikel[i].preis);
        printf("Bestand: %d\n", artikel[i].bestand);
    }
}

int hinzufuegen(struct lager artikel[], int *anzahl, int max)
{
    if (*anzahl >= max)
    {
        printf("Das Lager ist voll.\n");
        return 0;
    }

    struct lager neu;

    neu.artikelnummer = 1001 + *anzahl;

    printf("Artikelname (ohne Leerzeichen): ");
    fgets(neu.artikel, sizeof(neu.artikel), stdin);

    neu.artikel[strcspn(neu.artikel, "\n")] = '\0';

    if (neu.artikel[0] == '\0')
    {
        printf("Der Artikelname darf nicht leer sein!\n");
        return 0;
    }

    printf("Preis: ");
    if (scanf("%f", &neu.preis) != 1 || neu.preis < 0)
    {
        printf("Ungueltiger Preis!\n");
        return 0;
    }

    printf("Bestand: ");
    if (scanf("%i", &neu.bestand) != 1 || neu.bestand < 0)
    {
        printf("Ungueltiger Bestand!\n");
        return 0;
    }

    artikel[*anzahl] = neu;
    (*anzahl)++;

    printf("Artikel erfolgreich hinzugefuegt.\n");
    return 1;
}