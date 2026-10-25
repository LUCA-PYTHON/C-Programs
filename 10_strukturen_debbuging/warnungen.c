
/*
 * titel: Compiler-Warnungen verstehen
 * nr: 10.0
 * schwierigkeit: 1
 * themen: debugging, compiler, warnungen
 */

#include <stdio.h>

int main(void)
{
    int zahl = 10;
    int zweite_zahl = 20;

    // WARNUNG: Die Variable wird nicht verwendet.
    // Mit -Wall und -Wextra kann der Compiler darauf hinweisen.

    printf("Erste Zahl: %d\n", zahl);

    // BEHEBUNG:
    // zweite_zahl wird jetzt verwendet.
    // printf("Zweite Zahl: %d\n", zweite_zahl);

    printf("Summe: %d\n", zahl + zweite_zahl);

    return 0;
}
