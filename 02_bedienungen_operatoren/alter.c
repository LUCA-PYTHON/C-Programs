/*
titel: 02_Bedienungen_Projekt1
beschreibung: Abfrage ob eine Person volljährig (18 oder älter) ist
level: 1
themen: if/else
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
