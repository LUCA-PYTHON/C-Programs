#include <stdio.h>

int main(void){

    int beenden;

    do{
        printf("Gebe zum Beenden eine 0 ein: ");
        scanf("%i", &beenden);
    }while (beenden != 0);

    printf("Ablauf beendet.");
    return 0;
}
