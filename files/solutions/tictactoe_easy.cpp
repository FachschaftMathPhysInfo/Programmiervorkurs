#include <iostream>
#include <array>

std::string fts(int feld) {

    if (feld == 0) {
        return " ";
    } else if (feld == 1) {
        return "X";
    } else if (feld == 2) {
        return "O";
    } else {
        return "?";
    }
}

int frage_feld_nummer(std::array<int, 9> feld){
    int in = -1;
    bool valid = false;
    while (!valid) {
        std::cout << "Gib ein Feld ein (0-8): ";
        std::cin >> in;
        if (in < 0 || in > 8) {
            std::cout << "Ungültige Feldnummer!" << std::endl;
        }
        if (feld[in] != 0) {
            std::cout << "Feld ist besetzt!" << std::endl;
        } 
        else {
            valid = true; // Markiert die Eingabe als gültig wenn keine Fehler aufgetauch sind
        }
    }
    return in;
}

void gebe_feld_aus(std::array<int, 9> feld){
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << fts(feld[0]) << " | " << fts(feld[1]) << " | " << fts(feld[2]) << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << fts(feld[3]) << " | " << fts(feld[4]) << " | " << fts(feld[5]) << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << fts(feld[6]) << " | " << fts(feld[7]) << " | " << fts(feld[8]) << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

int gewinnerin(std::array<int, 9> feld){
   // Prüfe Reihen und Spalten
    for (int i = 0; i < 3; i++) {
        int a = feld[3*i] & feld[3*i+1] & feld[3*i+2];
        int b = feld[3*i] | feld[3*i+1] | feld[3*i+2];
        if (a == b && a != 0) {
            return feld[3*i];
        }
        a = feld[i] & feld[i+3] & feld[i+6];
        b = feld[i] | feld[i+3] | feld[i+6];
        if (a == b && a != 0) {
            return feld[i];
        }
    }
    // Prüfe Diagonale 1
    int a = feld[0] & feld[4] & feld[8];
    int b = feld[0] | feld[4] | feld[8];
    if (a == b && a != 0) {
        return feld[0];
    }

    // Prüfe Diagonale 2
    a = feld[2] & feld[4] & feld[6];
    b = feld[2] | feld[4] | feld[6];
    if (a == b && a != 0) {
        return feld[2];
    }

    for (int i = 0; i < 9; i++) {
        if (feld[i] == 0) {
            return 0;
        }
    }
    return 3;
}



int main() {
    // Setup
    std::array<int, 9> spielfeld{0};
    int current_player = 1;
    int input_player;

    while (true) {
        // Input
        input_player = frage_feld_nummer(spielfeld);
        
        // Update
        spielfeld[input_player] = current_player;
        int gewinner = gewinnerin(spielfeld);
        bool reset = false;
        
        if (gewinner == 1 || gewinner == 2 || gewinner == 3) { // Prüft ob das Spiel beendet ist
            reset = true;
            if (gewinner == 1) {
                std::cout << "Spieler 1 ist der Gewinner." << std::endl;
            } else if (gewinner == 2) {
                std::cout << "Spieler 2 ist der Gewinner." << std::endl;
            } else {
                std::cout << "Das Spiel endet unentschieden." << std::endl;
            }
        }

        if (current_player == 1) { // Wechselt den Spieler
            current_player = 2;
        } else {
            current_player = 1;
        }

        // Display
        gebe_feld_aus(spielfeld);

        if (reset) // Setzt das Spiel zurück falls es geendet hat
        {
            current_player = 1;
            for (int i = 0; i < 9; i++) {
                spielfeld[i] = 0;
            }
            reset = false;
        }
    }
    return 0;
}
