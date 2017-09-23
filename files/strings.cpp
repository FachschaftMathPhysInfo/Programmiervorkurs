#include <iostream>
#include <string>

int main() {
    std::cout << "Gebe deinen Namen ein:" << std::endl;

    std::string hallo;
    hallo = "Hallo ";

    std::string eingabe;
    std::cin >> eingabe;

    std::cout << hallo << eingabe << std::endl;

		return 0;
}
