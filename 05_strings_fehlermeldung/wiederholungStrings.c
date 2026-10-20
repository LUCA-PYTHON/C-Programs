/*5.4 Lernplan*/
/*Wiederholung der Strings mithilfe einer kleinen Kontaktkarte*/

#include <stdio.h>
#include <string.h>

int main(void){

    char name[10];
    char hobby[20];
    char ort[10];
    int alter;

    printf("Gebe dein Name an: ");
    fgets(name, sizeof(name), stdin);

    printf("Gebe dein Alter ein: ");
    scanf("%i", &alter);
    getchar();

    printf("Gebe ein Hobby ein: ");
    fgets(hobby, sizeof(hobby), stdin);

    printf("Gebe dein Wohnort ein: ");
    fgets(ort, sizeof(ort), stdin);

    name[strcspn(name, "\n")] = '\0';
    hobby[strcspn(hobby, "\n")] = '\0';
    ort[strcspn(ort, "\n")] = '\0';

    printf("\n\n-- Kontaktinformationen --\n");
    printf("Name: %s\n", name);
    printf("Alter: %i\n", alter);
    printf("Hobby: %s\n", hobby);
    printf("Wohnort: %s\n", ort);

    return 0;
}