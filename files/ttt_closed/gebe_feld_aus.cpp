#pragma once
#include <iostream>
#include <string>
#include <vector>

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

void gebe_feld_aus(std::vector<int> feld) {
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
