#include <stdio.h>

int main(void){

    double zahl1, zahl2, ergebnis;
    char zeichen;

    cout << "Erste Zahl";
    cin >> zahl1;

    cout << "Rechenzeichen";
    cin >> zeichen;

    cout << "Zahl2";
    cin >> zahl2;

    if (zeichen == '+'){
        ergebnis = zahl1 + zahl2;
        cout << "Ergebnis: "<< ergebnis;
    };

    else if (zeichen == '-'){
        ergebnis = zahl1 - zahl2;
        cout << "Ergebnis: "<< ergebnis;
    };

}