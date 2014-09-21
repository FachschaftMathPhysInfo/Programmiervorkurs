#include <iostream>
#include <string>

int main() {

    std::string name;
     std::string eingabe;
    std::string blub;
    name = "Laura";
    blub = "Sandra";

    std::cout << "Bitte gebe deinen Namen ein:" << std::endl;

   
    std::cin >> eingabe;

if (eingabe == name) {

    std::cout << "Wow, schöner Name, " << eingabe << "!" << std::endl;

} else {


if (eingabe == blub || eingabe == "Friedz") {
    std::cout << "Tschüss, " << eingabe << "!" << std::endl;

} else {
    std::cout << "Hallo " << eingabe << std::endl;
}
}
}
