#include <stdio.h>
#include "modul.h"

#define MAX_ARTIKEL 100

int main(void)
{

    struct lager meinLager[100] =
    {
        {
            1001,
            "Teil1",
            10.50,
            5
        },
        {
            1002,
            "Teil2",
            5.25,
            105
        },
        {
            1003,
            "Teil3",
            96.10,
            5
        }
    };

    int anzahl = 3;
    int nummer;

    do
    {
        printf("Menue\n");
        printf("1. Lager anzeigen\n2. Artikel hinzufuegen\n0. Beenden\n");
        
        printf("Auswahl: ");

        if (scanf("%d", &nummer) != 1)
        {
            printf("Ungueltige Eingabe!\n");

            int zeichen;
            while ((zeichen = getchar()) != '\n' && zeichen != EOF)
            {
            }

            nummer = -1;
            continue;
        }

        int zeichen;
        while ((zeichen = getchar()) != '\n' && zeichen != EOF)
        {
        }

        switch(nummer)
        {
            case 1:
                anzeigen(meinLager, anzahl);
                break;
            
            case 2:
                hinzufuegen(meinLager, &anzahl, MAX_ARTIKEL);
                break;

            case 0:
                printf("Programm beendet\n");
                break;
        }
    } while (nummer != 0);

    return 0;

}