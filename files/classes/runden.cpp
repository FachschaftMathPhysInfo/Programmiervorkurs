#include <iostream>

int runden(double d, int mode){
    // Input checking: falls Eingabe negativ, Fehlermeldung ausgeben
    if(d < 0){
        std::cerr << "Die Eingabe (" << d << ") ist negativ, unser Pro"
        "gramm rundet jedoch nur positive Zahlen korrekt." << std::endl;
        return 0;
    }
    
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
        std::cerr << "Beim Runden ist was schief gelaufen." << std::endl; 
        // Der Fehler kann zum Beispiel gewesen sein, dass der angegebene 
        // mode nicht verfügbar. Dies sollte idealerweise vom Programm 
        // zu Beginn geprüft werden. Falls der mode nicht valide ist, 
        // sollte eine Nachricht an den Nutzer ausgegeben werden.
        return 0;
    }
}

int main(){
    // hier lässt sich nicht intuitiv erkennen, was das Programm tut
    std::cout << runden(2.7, 0) << std::endl;
    std::cout << runden(2.3, 0) << std::endl;
    std::cout << runden(2.7, 1) << std::endl;
    std::cout << runden(2.7, 2) << std::endl;
    std::cout << runden(-1.4, 0) << std::endl;
    std::cout << runden(2.7, 3) << std::endl;
}
