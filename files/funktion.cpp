#include <iostream>

// bool ist ein neuer Datentyp. Ein Boolean kann genau zwei Werte
// annehmen, „true“ und „false“, repräsentiert also ein einziges
// Bit, beziehungsweise einen Wahrheitswert. In unserem Fall geben
// wir true zurück, wenn die Eingabe eine Primzahl ist und false,
// wenn sie keine ist.
bool istprim(int n) {
    int i = 2;
    while (i < n) {
        if ((i % n) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m;
    std::cout << "Gib eine Zahl ein: ";
    std::cin >> m;

    // Da istprim einen bool zurück gibt, müssen wir nicht
    // "istprim(n) == true" schreiben. Diese Schreibweise bedeutet
    // das Gleiche
    if (istprim(m)) {
        std::cout << m << " ist eine Primzahl" << std::endl;
    } else {
        std::cout << m << " ist keine Primzahl" << std::endl;
    }
}
