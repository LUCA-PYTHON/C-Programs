/*
 * titel: Countdown mit while-Schleife
 * nr: 3.1
 * schwierigkeit: 1
 * themen: schleifen, while
 */
#include <stdio.h>

int main(void){

    int i;
    int zahl = 15;

    while(zahl >= 0) {
        printf("%i\n", zahl--);
    }

}
