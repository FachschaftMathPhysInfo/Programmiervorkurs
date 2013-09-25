#include <iostream>

int frage_feld_nummer(int feld[9]) {
    int in = -1;
    while (true) {
        std::cout << "Gib ein Feld ein (0-8): ";
        std::cin >> in;
        if (in < 0 || in > 8) {
            std::cout << "Ungültige Feldnummer!" << std::endl;
            continue;
        }
        if (feld[in] != 0) {
            std::cout << "Feld ist besetzt!" << std::endl;
            continue;
        }
        break;
    }
    return in;
}
