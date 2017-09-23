#include <iostream>
#include <string>

int zaehle_a(std::string str) {
    int erg;

    unsigned i = 0;
    // unsigned funktioniert wie int,
    // kann allerdings keine negativen
    // Werte speichern.
    while (i < str.length()) {
        if (str[i] == 'a') {
            erg = erg + 1;
        }
        i = i + 1;
    }

    return erg;
}

int main() {
    std::string wort;

    std::cout << "Gib ein Wort ein: ";
    std::cin >> wort;

    std::cout << "In deinem Wort kommt " << zaehle_a(wort)
        << "-mal der Buchstabe a vor." << std::endl;
    return 0;
}
