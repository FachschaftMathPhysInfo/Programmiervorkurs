#include <iostream>

int main() {
    int a, b;

    std::cout << "Gebe eine Zahl ein: ";
    std::cin >> a;

    std::cout << "Gebe noch eine Zahl ein: ";
    std::cin >> b;

    if (b == 0) {
        // std::cerr ist eine weitere Möglichkeit der Ausgabe, die
        // für Fehler verwendet wird. Ihr seht dies genauso wie
        // den output von std::cout auf der Konsole, aber man kann
        // diesen output besonders behandeln
        std::cerr << "Die zweite Zahl darf nicht 0 sein!" << std::endl;
    } else {
        std::cout << "Ihr Quotient ist " << a / b << std::endl;
    }
		return 0;
}
