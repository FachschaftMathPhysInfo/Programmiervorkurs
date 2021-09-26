#include <iostream>

int collatz(int x) {
    int erg;

    if (x % 2 == 0) {
        erg = x / 2;
    } else {
        erg = 3*x + 1;
    }

    return erg;
}

int main() {
    int eingabe;

    std::cout << "Mit welcher Zahl moechtest du starten? ";
    std::cin >> eingabe;

    int x1 = collatz(eingabe);
    int x2 = collatz(x1);
    int x3 = collatz(x2);
    //bis hierin haben keine Ausgaben statt gefunden, aber collatz wurde
    //dreimal aufgerufen. Die Zahlen x1, x2 und x3 sind die naechsten
    //drei Glieder von x (der von der Nutzerin eingegebenen Zahl) aus
    //gesehen.

    //Hier werden der Nutzerin nun die Ergebnisse angezeigt:
    std::cout << eingabe << " -> " << x1 << " -> "
        << x2 << " -> " << x3 << std::endl;
    return 0;
}
