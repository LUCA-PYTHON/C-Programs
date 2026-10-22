/*
 * titel: Einmaleins mit for-Schleife
 * nr: 3.0
 * schwierigkeit: 1
 * themen: schleifen, for
 */
#include <stdio.h>

int main(void){

    int i;
    float zahl;
    
    printf("Eingabe (Zahl): ");
    scanf("%f", &zahl);

    for (i=0; i<10; i++){
        printf("%.2f x %i = %.2f\n", zahl, i, zahl * i);
    }
}