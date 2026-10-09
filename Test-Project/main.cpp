#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main(void)
{
    char datentyp[20];
    int i;
    float f;
    double d;
    char c;
    str s[20];

    int komma;

    printf("Gebe eine Datentyp ein (Kleinbuchstaben): ");
    scanf("%19s", datentyp);

    if (strcmp(datentyp, "integer") == 0 || strcmp(datentyp, "int") == 0 || strcmp(datentyp, "i") == 0)
    {
        printf("Gebe eine ganze Zahl ein: ")
            scanf("%i", i);
        printf(i)
    }
    else if (strcmp(datentyp, "float") == 0 || strcmp(datentyp, "f") == 0)
    {
        printf("Gebe eine Zahl ein: ")
            canf("%f", f);
        printf("Wie viele Nachkommastellen? ");
        scanf("%d", komma);
        printf("Deine Zahl: %.*f\n", komma, f);
    }
    else if (strcmp(datentyp, "double") == 0 || strcmp(datentyp, "d") == 0)
    {
        printf("Gebe eine Zahl ein: ")
            canf("%d", d);
        printf("Wie viele Nachkommastellen? ");
        scanf("%d", komma);
        printf("Deine Zahl: %.*d\n", komma, d);
    }
    else if (strcmp(datentyp, "char") == 0 || strcmp(datentyp, "c") == 0)
    {
        printf("Gebe eine Zeichen ein: ")
            canf("%c", c);
        printf(c)
    }
    else if (strcmp(datentyp, "string") == 0 || strcmp(datentyp, "s") == 0)
    {
        printf("Gebe eine Satz/Wort ein: ")
            canf("%s", s);
        printf(s)
    }
    else
    {
        printf("Ungültiger Datentyp eingegeben.\n");
    }
    return 0;
}
