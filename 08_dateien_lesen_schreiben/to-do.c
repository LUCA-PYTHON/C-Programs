/*
 * titel: ToDO Liste
 * nr: 8.6
 * schwierigkeit: 3
 * themen: dateien, while, schleifen, funktionen, switch/case
 */
#include <stdio.h>
#include <string.h>

int add(char task[50])
{
    FILE *datei = fopen("database/dateien/to-do.txt", "a");

    if (datei == NULL)
    {
        printf("Datei nicht gefunden");
        return 0;
    }
    fprintf(datei, "%s\n", task);
    fclose(datei);

    return 1;
}

int show(void)
{
    FILE *datei = fopen("database/dateien/to-do.txt", "r");

    if (datei == NULL)
    {
        printf("Datei nicht gefunden");
        return 0;
    }

    char zeile[250];
    int count = 0;

    while (fgets(zeile, sizeof(zeile), datei) != 0)
    {
        count++;
        printf("%i. %s", count, zeile);
    }
    fclose(datei);

    return 1;
}

int main(void)
{
    int eingabe, erfolg = 0;
    char task[50];
    int c;

    printf("ToDo Liste\n");
    printf("1. Hinzufuegen\n2. Anzeigen\n");
    scanf("%i", &eingabe);

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    switch (eingabe)
    {

    case 1:
        printf("Task: ");
        if (fgets(task, sizeof(task), stdin) != NULL)
        {
            task[strcspn(task, "\n")] = '\0';
            erfolg = add(task);
        }
        break;

    case 2:
        erfolg = show();
        break;

    default:
        printf("Ungueltige Eingabe");
        return 0;
    }

    if (erfolg)
    {
        printf("\nErfolgreich ausgefuehrt");
        return 1;
    }

    printf("Fehlgeschlgen");
    return 1;
}