#include <iostream>

int main() {
    int n;
    std::cout << "Gebe eine Zahl ein: " << std::endl;
    std::cin >> n;

    if (n = 0) {
        std::cout << "Null!" << std::endl;
    } else {
        std::cout << "Nicht Null!" << std::endl;
    }
    return 0;
}
