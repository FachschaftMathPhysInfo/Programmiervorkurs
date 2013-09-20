#include <iostream>

int main() {
    int a, b, c;

    std::cout << "Gebe eine Zahl ein: ";
    std::cin >> a;

    std::cout << "Noch eine: ";
    std::cin >> b;

    c = a + b;
    a = b / c;
    c = 2 * a + b;

    std::cout << "c ist jetzt " << c << std::endl;
}
