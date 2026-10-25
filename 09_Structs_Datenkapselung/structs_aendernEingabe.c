/*
 * titel: Structs Ändern
 * nr: 9.3
 * schwierigkeit: 3
 * themen: struct, funktionen, string
 */
#include <stdio.h>

struct aufgabe
{
    char aufgabe[100];
    int status;
};

void anzeigen(struct aufgabe b)
{
    printf("Aufgabe: %s\n", b.aufgabe);

    const char *check;
    if (b.status == 1)
    {
        check = "Erledigt";
    }
    else
    {
        check = "unerledigt";
    }
    printf("Status: %s\n\n", check);
}

void erledigt(struct aufgabe *b, int neuerStatus)
{
    b->status = neuerStatus;
}

int main(void)
{
    struct aufgabe meineAufgabe[5] =
    {
        {
            "Aufgabe 1",
            0
        },
        {
            "Aufgabe 2",
            0
        },
        {
            "Aufgabe 3",
            0
        },
        {
            "Aufgabe 4",
            0
        },
        {
            "Aufgabe 5",
            0
        }
    };

    for (int i = 0; i < 5; i++)
    {
        anzeigen(meineAufgabe[i]);
    }

    int nummer = 0;
    printf("Aufgabe als erledigt markieren (1-5): ");
    scanf("%i", &nummer);

    for (int i = 0; i < nummer; i++)
    {
        if (nummer < 1 || nummer > 5)
        {
            printf("Ungueltige Eingabe");
            return 1;
        }
        if (meineAufgabe[nummer -1].status == 0)
        {
            erledigt(&meineAufgabe[nummer -1], 1);
            printf("Aufgabe %i wurde als erledigt markiert. \n", nummer);
        }
        else
        {
            printf("Aufgabe %i ist bereits erledigt", nummer);
        }
    }

    printf("Aktueller Aufgabenstatus:\n");
    for (int i = 0; i < 5; i++)
    {
        anzeigen(meineAufgabe[i]);
    }

    return 0;

}