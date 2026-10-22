/*
 * titel: Notenbewertung
 * nr: 2.2
 * schwierigkeit: 1
 * themen: if/else, logische operatoren
 */
#include <stdio.h>

int main(void)
{
    int note;

    printf("Punktzahl (0-100): ");
    scanf("%i", &note);

    if (note < 100 && note >= 90)
    {
        printf("Sehr gut");
    }
    else if (note < 90  && note >= 75)
    {
        printf("Gut");
    }
    else if (note < 75 && note >= 60)
    {
        printf("Ausreichend");
    }
    else if (note < 60 && note >= 40)
    {
        printf("Befriedigend");
    }
    else if (note <= 39 || note < 40)
    {
        printf("Nicht bestanden!");
    }
}
