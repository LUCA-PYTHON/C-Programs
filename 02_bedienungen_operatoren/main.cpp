/*C++ Lernplan Teil2*/
/*Lernen von Eingabe/Ausgabe und Auswerten der Eingabe. Deutsch mehr IF/ELSE Abfragen.*/
#include <iostream>

using namespace std;

int main(void)
{
    float zahl;

    cout << "Eingabe: ";
    cin >> zahl;
    cout << endl;

    if (zahl > 0)
    {
        cout << "Positive Zahl";
    }
    else if (zahl < 0)
    {
        cout << "Negative Zahl";
    }
    else if (zahl == 0)
    {
        cout << "Zahl ist Null";
    }
    else
    {
        cout << "Error";
    }
}