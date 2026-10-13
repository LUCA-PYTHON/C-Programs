/*C++ Lernplan Teil1*/
/*Lernen von Eingabe/Ausgabe und Rechnen mit den Eingaben. Dazu alles sauber und verständlich ausgeben.*/
/*Bei Nenner (Division) Null Fehlermeldung anzeigen.*/
#include <iostream>

using namespace std;

int main(void)
{

    float zahl1, zahl2;
    char rechenzeichen;

    cout << "Zahl 1: ";
    cin >> zahl1;
    cout << "Zahl 2: ";
    cin >> zahl2;

    cout << "Addition: " << zahl1 + zahl2 << endl;
    cout << "Subtraktion: " << zahl1 + zahl2 << endl;
    cout << "Multiplikation: " << zahl1 * zahl2 << endl;
    if (zahl2 != 0)
    {
        cout << "Division: " << zahl1 / zahl2 << endl;
    }
    else
    {
        cout << "Error! Kein Nenner mit 0!";
    };
}