/*
 * titel: Taschenrechner mit Befehlsmenü und Verlauf
 * nr: 98.0
 * schwierigkeit: 3
 * themen: projekt, struct, strings, funktionen
 */
#include <stdio.h>
#include <stdlib.h> /*allgemeine Funktionen z.B. umwandeln von Text in Zahlen*/
#include <string.h> /*Zeichenkettenfunktionen*/
#include <time.h>   /*Zeitfunktionen*/
#include <ctype.h>  /*Erkennen von leerzeichen*/

/*Farben für Terminal definieren*/
#define ORANGE "\033[38;5;208m"
#define PURPLE "\033[38;5;141m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define GRAY "\033[90m"
#define WHITE "\033[97m"
#define RESET "\033[0m"

/*Konstanten für die Eingabegröße*/
#define MAX_BEFEHL 100

/*Einträge im Rechenverlauf*/
typedef struct{

    double erste_Zahl;
    double zweite_Zahl;
    double ergebnis;
    char rechenzeichen;
} Rechnung;

/*Hilfe Menü*/
void hilfe_anzeigen(void){

    printf(ORANGE "\nVerfügbare Befehle:\n" RESET);
    printf(GREEN "/addition" RESET "        Zwei Zahlen addieren\n");
    printf(GREEN "/subtraction" RESET "     Zwei Zahlen subtrahieren\n");
    printf(GREEN "/multiplication" RESET "  Zwei Zahlen multiplizieren\n");
    printf(GREEN "/division" RESET "        Zwei Zahlen dividieren\n");
    printf(GREEN "/help" RESET "            Diese Hilfe anzeigen\n");
    printf(GREEN "/exit" RESET "            Programm beenden\n\n");
}

/*Rechenfunktion*/
void rechnen(char rechenzeichen){

    double erste_zahl, zweite_zahl, ergebnis;
    int zeichen;

    printf("Erste Zahl: ");
    if (scanf("%lf", &erste_zahl) != 1) {
        printf(RED "Ungültige Zahl!\n\n" RESET);

        /*Löschen was noch in der Eingabe steht*/
        while ((zeichen = getchar()) != '\n' && zeichen != EOF) {

        }
        return;
    }

    printf("Zweite Zahl: ");
    if (scanf("%lf", &zweite_zahl) != 1) {
        printf(RED "Ungültige Zahl!\n\n" RESET);

        /*Löschen was noch in der Eingabe steht*/
        while ((zeichen = getchar()) != '\n' && zeichen != EOF) {

        }
        return;
    }

    while ((zeichen = getchar()) != '\n' && zeichen != EOF) {

    }

    if (rechenzeichen == '+') {
        ergebnis = erste_zahl + zweite_zahl;
    } else if (rechenzeichen == '-') {
        ergebnis = erste_zahl - zweite_zahl;
    } else if (rechenzeichen == '*') {
        ergebnis = erste_zahl * zweite_zahl;
    } else {
        if (zweite_zahl == 0) {
            printf(RED "Durch null darf man nicht teilen.\n\n" RESET);
            return;
        }
        ergebnis = erste_zahl / zweite_zahl;
    }

    printf(GREEN "Ergebnis:" RESET " %g\n\n", ergebnis);

}

/*Hauptfunktion*/
int main(void){

    char befehl[MAX_BEFEHL];

    printf("Ubuntu Taschenrechner\n");
    printf("Gib /help ein, um alle Befehle zu sehen. \n\n");

    while (1) {

        /*Eingabe Benutzer*/
        printf("> ");

        if (fgets(befehl, sizeof(befehl), stdin) == NULL) {
            break;
        }

        /* Das Zeilenende entfernen, damit Befehle verglichen werden können. */
        befehl[strcspn(befehl, "\n")] = '\0';

        if (strcmp(befehl, "/addition") == 0){
            rechnen('+');
        } else if (strcmp(befehl, "/subtraction") == 0){
            rechnen('-');
        } else if (strcmp(befehl, "/multiplication") == 0){
            rechnen('*');
        } else if (strcmp(befehl, "/division") == 0){
            rechnen('/');
        } else if (strcmp(befehl, "/help") == 0){
            hilfe_anzeigen();
        } else if (strcmp(befehl, "/exit") == 0){
            printf("Programm beendet.\n");
            break;
        } else if (befehl[0] != '\0'){
            printf("Unbekannter Befehl. Gib /help ein.\n\n");
        }
    }

    return 0;
}
