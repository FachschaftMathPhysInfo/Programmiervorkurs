#include <iostream>

int main() {
  // Hier initialisieren wir das Array
  int numbers[5] = {1, 4, 3, 9, 100};

  // Wir zählen ab 0, das 5. Element hat also den Index 4
  int letzteZahl = numbers[4];

  // So könnte man das Array in der Konsole ausgeben 
  std::cout << "Das Array beinhaltet die Zahlen" << std::endl;
  
  for (int n = 0; n < 5; n++) {
    std::cout << numbers[n] << "  ";
  }

  return 0;
}
