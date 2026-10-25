/*
 * titel: Structs verwenden
 * nr: 9.0
 * schwierigkeit: 1
 * themen: struct
 */
#include <stdio.h>

struct buch
{
    char titel[20];
    int seiten;
};

int main(void)
{
    struct buch meinBuch = {"Erstes Struct", 999};

    printf("Titel: %s\n", meinBuch.titel);
    printf("Seite: %i", meinBuch.seiten);

    return 0;
}