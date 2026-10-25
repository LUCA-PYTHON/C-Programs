/*
 * titel: Structs verwenden mit Funktionen Erweiterung
 * nr: 9.3
 * schwierigkeit: 2
 * themen: struct, funktionen, string, schleifen, for
 */
#include <stdio.h>
#include <string.h>

struct buch
{
    char titel[100];
    int seiten;
};

struct buch buchErstellen(const char titel[], int seiten)
{
    struct buch b;
    snprintf(b.titel, sizeof(b.titel), "%s", titel);
    b.seiten = seiten;

    return b;
}

void anzeigen(struct buch b)
{
    printf("Titel: %s\n", b.titel);
    printf("Seiten: %i\n", b.seiten);
}

void seitenAendern(struct buch *b, int neueSeiten)
{
    b->seiten = neueSeiten;
}

void titelAendern(struct buch *b, const char neuerTitel[])
{
    snprintf(b->titel, sizeof(b->titel), "%s", neuerTitel);
}

int main(void)
{
    struct buch meinBuch[3] = {
        {
            "C-Lernen",
            350
        },
        {
            "C-Lernen Teil2",
            360
        },
        {
            "C-Lernen Teil3",
            400
        }
    };

    // Alle Bücher anzeigen
    for (int i = 0; i<3; i++)
    {
        anzeigen(meinBuch[i]);
    }

    // Erstes Eintrag wird verändert
    titelAendern(&meinBuch[0], "C-Lernen Grundlagen");
    seitenAendern(&meinBuch[0], 375);

    printf("\nNach Aenderungen:\n");
    for (int i = 0; i < 3; i++)
    {
        anzeigen(meinBuch[i]);
    }

    return 0;
}