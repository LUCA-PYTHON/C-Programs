/*
 * titel: Array: Summe und Durchschnitt
 * nr: 6.1
 * schwierigkeit: 2
 * themen: arrays, for, sizeof, durchschnitt
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    float zahlen[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //Arrey festlegen
    float summe = 0;
    float durchschnitt;

    for (int i = 0; i < 10; i++){
        printf("Zahl: %.2f\n", zahlen[i]);  // [i] gibt an welchen arrey wir raus holen wollen

        summe = summe + zahlen[i]; // Summe des Arrays berechen
    }

    durchschnitt = summe / (sizeof(zahlen) / sizeof(zahlen[0]));  // Durchschnitt berechenen mithilfe der Summe / gesamte größer des arrays (bytes) / die größe jedes elemnts

    printf("Summe: %i\n", summe);
    printf("Durchschnitt: %.2f", durchschnitt);

    return 0;
}
