/*
 * titel: istGerade funktion
 * schwierigkeit: 1
 * themen: funktionen, modulo, if/else
 */
#include <stdio.h>

int istGerade(int zahl){
    if (zahl % 2 == 0){
        return 1;
    }
    else {
        return 0;
    }
}

int main(void)
{
    int zahl;
    int gerade;

    printf("Eingabe (zahl): ");
    scanf("%i", &zahl);

    gerade = istGerade(zahl);

    if (gerade == 1){
        printf("Zahl ist gerade");
    }
    else {
        printf("Zahl ist ungerade");
    }

}
