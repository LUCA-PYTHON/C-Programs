#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main(void)
{
    char datentyp[20];
    printf("Gebe eine Datentyp ein (Kleinbuchstaben): ");
    scanf("%19s", datentyp);

    if (strcmp(datentyp, "integer") == 0 || strcmp(datentyp, "int") == 0 || strcmp(datentyp, "i") == 0) {
        printf("Du hast den Datentyp Integer gewählt.\n");
    } else if (strcmp(datentyp, "float") == 0 || strcmp(datentyp, "f") == 0) {
        printf("Du hast den Datentyp Float gewählt.\n");
    } else if (strcmp(datentyp, "double") == 0 || strcmp(datentyp, "d") == 0) {
        printf("Du hast den Datentyp Double gewählt.\n");
    } else if (strcmp(datentyp, "char") == 0 || strcmp(datentyp, "c") == 0) {
        printf("Du hast den Datentyp Char gewählt.\n");
    } else if (strcmp(datentyp, "string") == 0 || strcmp(datentyp, "s") == 0) {
        printf("Du hast den Datentyp String gewählt.\n");
    } else {
        printf("Ungültiger Datentyp eingegeben.\n");
    }
    return 0;

}
