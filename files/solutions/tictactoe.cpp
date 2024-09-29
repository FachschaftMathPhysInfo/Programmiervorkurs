#include <iostream>
#include <array>

static std::string fts(int feld) {
    switch (feld) {
    case 0:
        return " ";
    case 1:
        return "X";
    case 2:
        return "O";
    default:
        return "?";
    }
}

int frage_feld_nummer(std::array<int, 9> feld){
    int in = -1;
    while (true) {
        std::cout << "Gib ein Feld ein (0-8): ";
        std::cin >> in;
        if (in < 0 || in > 8) {
            std::cout << "Ungültige Feldnummer!" << std::endl;
            continue;
        }
        if (feld[in] != 0) {
            std::cout << "Feld ist besetzt!" << std::endl;
            continue;
        }
        break;
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
   // Prüfe reihen und Spalten
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
restart:
    std::array<int, 9> spielfeld{0};
    int current_player = 1;
    int input_player;

    while (true) {
        // Input
        input_player = frage_feld_nummer(spielfeld);
        
        // Update
        spielfeld[input_player] = current_player;
        int gewinner = gewinnerin(spielfeld);
        switch (gewinner) {
          case 1:
              std::cout << "Spieler 1 ist der Gewinner." << std::endl;
              goto restart;
              
          case 2:
              std::cout << "Spieler 2 ist der Gewinner." << std::endl;
              goto restart;

          case 3:
              std::cout << "Das Spiel endet unentschieden." << std::endl;
              goto restart;

          default:
              current_player = (current_player == 2) ? 1 : 2;
              break;
    }


        // Display
        gebe_feld_aus(spielfeld);
    }
    return 0;
}
