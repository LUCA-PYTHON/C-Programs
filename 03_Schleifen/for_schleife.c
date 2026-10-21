/*
   * titel: for-Schleife
   * schwierigkeit: 1
   * themen: for-schleifen
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