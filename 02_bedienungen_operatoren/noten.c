/*C Lernplan Teil2.2*/
/* Noten IF/ELSE abfrage (Simpel)*/
#include <stdio.h>

int main(void)
{
    int note;

    printf("Punktzahl (0-100): ");
    scanf("%i", &note);

    if (note >= 90)
    {
        printf("Sehr gut");
    }
    else if (note >= 75)
    {
        printf("Gut");
    }
    else if (note >= 60)
    {
        printf("Ausreichend");
    }
    else if (note >= 40)
    {
        printf("Befriedigend");
    }
    else if (note < 40)
    {
        printf("Nicht bestanden!");
    }
}
