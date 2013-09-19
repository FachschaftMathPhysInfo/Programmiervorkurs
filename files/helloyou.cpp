#include <iostream>
#include <string>

int main() {
    std::cout << "Bitte gebe deinen Namen ein:" << std::endl;

    std::string eingabe;
    std::cin >> eingabe;

    std::cout << "Hallo " << eingabe << std::endl;
}
