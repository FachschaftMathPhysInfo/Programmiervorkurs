#include <iostream>
#include <string>

int zaehlen(std::string str, char c) {
    int erg;

    unsigned i = 0;
    // unsigned funktioniert wie int,
    // kann allerdings keine negativen
    // Werte speichern.
    while (i < str.length()) {
        if (str[i] == c) {
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

    std::cout << "In deinem Wort kommt " << zaehlen(wort, 'a')
        << "-mal der Buchstabe a vor." << std::endl;
}
