#include <iostream>

int main() {
    int n;
    std::cout << "Gebe eine (positive) Zahl ein: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Die Zahl soll positiv sein!" << std::endl;
        // Wir benutzen return, um unser Programm vorzeitig
        // abzubrechen. 1 bedeutet, dass ein Fehler aufgetreten
        // ist, 0 bedeutet, alles ist okay
        return 1;
    }

    int i = 2;
    bool hat_teiler = false;
    while (i < n) {
        if ((n % i) == 0) {
            hat_teiler = true;
        }
        i = i + 1;
    }

    if (hat_teiler) {
        std::cout << n << " ist keine Primzahl" << std::endl;
    }
    else {
        std::cout << n << " ist eine Primzahl" << std::endl;
    }
    return 0;
}
