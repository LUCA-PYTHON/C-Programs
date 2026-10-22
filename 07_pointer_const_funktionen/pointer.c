/*
 * titel: Pointer Erklärung
 * nr: 7.1
 * schwierigkeit: 3
 * themen: pointer, variablen, funktionen
 */
#include <stdio.h>

/* Zeigt den aktuellen Zustand: Schubladen (x, y) und Zettel (a, b) */
void zeige(const char *titel, int *x, int *y, int **a, int **b)
{
    printf("--- %s ---\n", titel);
    printf("Schublade x: Inhalt %2d   (Adresse %p)\n", *x, (void *)x);
    printf("Schublade y: Inhalt %2d   (Adresse %p)\n", *y, (void *)y);
    printf("Zettel a: nennt %p  -> %s\n", (void *)*a, *a == x ? "Schublade x" : "Schublade y");
    printf("Zettel b: nennt %p  -> %s\n", (void *)*b, *b == x ? "Schublade x" : "Schublade y");
    printf("Also: *a = %2d, *b = %2d\n\n", **a, **b);
}

int main(void)
{
    int x = 10, y = 20;
    int *a = &x;
    int *b = &y;

    zeige("START", &x, &y, &a, &b);

    printf("TEIL 1: WERTE TAUSCHEN\n");
    printf("Wir aendern, WAS IN den Schubladen liegt.\n\n");

    int temp = *a;
    printf("temp = *a;   -> Inhalt von x (%d) auf den Notizblock\n", temp);

    *a = *b;
    printf("*a = *b;     -> Inhalt von y in Schublade x legen\n");

    *b = temp;
    printf("*b = temp;   -> Notizblock in Schublade y legen\n\n");

    zeige("NACH WERTE-TAUSCH", &x, &y, &a, &b);
    printf("Merke: x und y haben getauscht. Die Zettel zeigen unveraendert\n");
    printf("auf dieselben Schubladen (a -> x, b -> y).\n\n");

    printf("TEIL 2: POINTER TAUSCHEN\n");
    printf("Wir aendern, WELCHE Schublade die Zettel nennen.\n\n");

    int *ptemp = a;
    printf("ptemp = a;   -> Zettel a abschreiben\n");

    a = b;
    printf("a = b;       -> auf Zettel a steht jetzt, was auf b steht\n");

    b = ptemp;
    printf("b = ptemp;   -> auf Zettel b kommt die Abschrift\n\n");

    zeige("NACH POINTER-TAUSCH", &x, &y, &a, &b);
    printf("Merke: x und y sind UNVERAENDERT (Inhalt gleich, Adresse gleich).\n");
    printf("Aber a zeigt jetzt auf y und b auf x, darum ist *a = %d und *b = %d.\n", *a, *b);

    return 0;
}