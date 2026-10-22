/*
 * titel: Volljährigkeits-Check
 * nr: 2.1
 * schwierigkeit: 1
 * themen: if/else, vergleiche
 */
#include <stdio.h>

int main(void)
{
    int alter;

    printf("Gebe dein Alter ein: ");
    scanf("%3.0i", alter);
    printf("\n");

    if (alter >= 18){
        printf("Volljährig");
    }
    else if (alter < 18){
        printf("nicht Volljährig");
    }
}
