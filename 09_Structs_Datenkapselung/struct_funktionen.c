/*
 * titel: Structs verwenden mit Funktionen
 * nr: 9.1
 * schwierigkeit: 2
 * themen: struct, string, funktionen
 */
#include <stdio.h>
#include <string.h>

struct buch
{
    char titel[100];
    int seiten;
};

void anzeigen(struct buch b)
{
    printf("Titel: %s\n", b.titel);
    printf("Seite: %i\n", b.seiten);
}

void seitenAendern(struct buch *b, int neueSeiten)
{
    b->seiten = neueSeiten;
}

struct buch buchErstellen(const char titel[], int seiten)
{
    struct buch b;

    snprintf(b.titel, sizeof(b.titel), "%s", titel);
    b.seiten = seiten;

    return b;
}

int main(void)
{
    struct  buch meinBuch =
    {
        "C-Lernen",
        350
    };

    anzeigen(meinBuch);

    seitenAendern(&meinBuch, 400);

    printf("%s hat %d Seiten nach Aenderung.\n", meinBuch.titel, meinBuch.seiten);

    struct buch meinBuch2 = buchErstellen("Teil 2 von C-Lernen", 310);

    anzeigen(meinBuch2);

    return 0;
    
}