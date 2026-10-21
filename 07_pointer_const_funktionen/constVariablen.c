/*
 * titel: constVariablen
 * schwierigkeit: 1
 * themen: const
 */
#include <stdio.h>

int main(void){
    
    const int MAX_PUNKTE = 100;  // Konstante Variable (nicht veränderbar)
    int punkte = 99;

    if (MAX_PUNKTE < punkte){
        printf("Zu viele Punkte angegeben!");
    }
    else {
        printf("Punktzahl ist gueltig.");
    }

}