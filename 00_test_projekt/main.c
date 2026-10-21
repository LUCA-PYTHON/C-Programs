/*
titel: Test Projekt
level: 1
themen: -
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char datentyp[20];
    int i;
    float f;
    double d;
    char c;
    char s[100];

    int komma;

    printf("Gebe eine Datentyp ein (Kleinbuchstaben): ");
    scanf("%19s", datentyp);

    if (strcmp(datentyp, "integer") == 0 || strcmp(datentyp, "int") == 0 || strcmp(datentyp, "i") == 0)
    {
        printf("Gebe eine ganze Zahl ein: ");
        scanf("%d", &i);
        printf("Deine Zahl: %d\n", i);
    }
    else if (strcmp(datentyp, "float") == 0 || strcmp(datentyp, "f") == 0)
    {
        printf("Gebe eine Zahl ein: ");
        scanf("%f", &f);
        printf("Wie viele Nachkommastellen? ");
        scanf(" %d", &komma);
        printf("Deine Zahl: %.*f\n", komma, f);
    }
    else if (strcmp(datentyp, "double") == 0 || strcmp(datentyp, "d") == 0)
    {
        printf("Gebe eine Zahl ein: ");
        scanf("%lf", &d);
        printf("Wie viele Nachkommastellen? ");
        scanf(" %d", &komma);
        printf("Deine Zahl: %.*lf\n", komma, d);
    }
    else if (strcmp(datentyp, "char") == 0 || strcmp(datentyp, "c") == 0)
    {
        printf("Gebe eine Zeichen ein: ");
        scanf("%c", &c);
        printf("Dein Zeichen: %c\n", c);
    }
    else if (strcmp(datentyp, "string") == 0 || strcmp(datentyp, "s") == 0)
    {
        printf("Gebe eine Satz/Wort ein: ");
        scanf("%99s", s);
        printf("Dein Satz/Wort: %s\n", s);
    }
    else
    {
        printf("Ungültiger Datentyp eingegeben.\n");
    }
    return 0;
}
