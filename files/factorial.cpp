#include <iostream>

int main() {
    
    int number;
    int ergebnis;
       
    std::cout << "Die Fakultät welcher Zahl \
    (>0) möchtest du wissen?" << std::endl;
    
    std::cin >> number;

    ergebnis = 0;

    for(int i = number; i>=0; i--) {
        ergebnis = ergebnis * i;
    }
    
    std::cout << "Die Fakultät von " << number 
    << " ist: " << ergebnis << std::endl;

    return 0;
}
