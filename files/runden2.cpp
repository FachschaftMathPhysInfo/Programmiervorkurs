#include <iostream>

enum Runden{
    mathe,
    ab,
    auf
};

int runden(double d, Runden mode){
    int i = d; // speichert Double in Integer, schneidet Kommastellen ab
    if(mode == mathe){
        if(d - i < 0.5){
            return i;
        }
        else {
            return i + 1;
        }
    }
    else if (mode == ab){
        return i;
    }
    else if (mode == auf){
        return i + 1;
    }
    else {
        return 0; // Hier sollte ein Fehler geworfen werden. Das könnt ihr noch nicht
    }
}

int main(){
    // hier lässt sich sehr(!) intuitiv erkennen, was das Programm tut
    std::cout << runden(2.7, mathe) << std::endl;
    std::cout << runden(2.3, mathe) << std::endl;
    std::cout << runden(2.7, ab) << std::endl;
    std::cout << runden(2.7, auf) << std::endl;
    return 0;
}
