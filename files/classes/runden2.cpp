#include <iostream>

enum Runden {
    kaufmaennisch,
    ab,
    auf
};

int runden(double d, Runden mode) {
    // speichert Double als Integer -> schneidet Kommastellen ab
    int i = d;
    if(mode == kaufmaennisch) {
        if(d - i < 0.5){
            return i;
        }
        else {
            return i + 1;
        }
    }
    else if (mode == ab) {
        return i;
    }
    else if (mode == auf) {
        return i + 1;
    }
}

int main() {
    // hier lässt sich sehr(!) intuitiv erkennen, was das Programm tut
    std::cout << runden(2.7, kaufmaennisch) << std::endl;
    std::cout << runden(2.3, kaufmaennisch) << std::endl;
    std::cout << runden(2.7, ab) << std::endl;
    std::cout << runden(2.7, auf) << std::endl;
}
