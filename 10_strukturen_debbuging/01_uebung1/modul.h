
#ifndef MODUL_H
#define MODUL_H

struct lager
{
    int artikelnummer;
    char artikel[20];
    float preis;
    int bestand;
};

void anzeigen(const struct lager artikel[], int anzahl);

int hinzufuegen(struct lager artikel[], int *anzahl, int max);

#endif
