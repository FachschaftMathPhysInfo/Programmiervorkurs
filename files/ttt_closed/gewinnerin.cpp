int gewinnerin(int feld[9]) {
    int a, b;
    // Prüfe reihen und Spalten
    for (int i = 0; i < 3; i++) {
        a = feld[3*i] & feld[3*i+1] & feld[3*i+2];
        b = feld[3*i] | feld[3*i+1] | feld[3*i+2];
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
    a = feld[0] & feld[4] & feld[8];
    b = feld[0] | feld[4] | feld[8];
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
