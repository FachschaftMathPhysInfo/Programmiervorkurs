#include <iostream>

int main() {
    int n;
    std::cout << "Gebe eine Zahl ein: " << std::endl;
    std::cin >> n;

    if (n = 0) {
        std::cout << "n = " << n
            << ", also ist n Null!" << std::endl;
    } else {
        std::cout << "n = " << n
            << ", also ist n nicht Null!" << std::endl;
    }
    return 0;
}
