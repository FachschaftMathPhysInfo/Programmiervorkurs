#include <iostream>

int main() {
    int n;
    std::cout << "Gebe eine Zahl ein: ";
    std::cin >> n;

    std::cout << n;
    int i;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3*n + 1;
        }
        std::cout << ", " << n;
        i = i + 1;
    }
    std::cout << std::endl << "Nach " << i << " Schritten erhalten wir 1" << std::endl;
}
