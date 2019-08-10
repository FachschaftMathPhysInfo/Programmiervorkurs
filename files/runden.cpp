#include <iostream>

int runden(double d, int mode){
    // speichert Double als Integer -> schneidet Kommastellen ab
    int i = d;
    if(mode == 0){ // kaufmaennisch runden
        if(d - i < 0.5){
            return i;
        }
        else {
            return i + 1;
        }
    }
    else if (mode == 1){ // abrunden
        return i;
    }
    else if (mode == 2){ // aufrunden
        return i + 1;
    }
    else {
        // Hier sollte ein Fehler geworfen werden.
        // Das könnt ihr aber leider noch nicht
        return 0;
    }
}

int main(){
    // hier lässt sich nicht intuitiv erkennen, was das Programm tut
    std::cout << runden(2.7, 0) << std::endl;
    std::cout << runden(2.3, 0) << std::endl;
    std::cout << runden(2.7, 1) << std::endl;
    std::cout << runden(2.7, 2) << std::endl;
}
