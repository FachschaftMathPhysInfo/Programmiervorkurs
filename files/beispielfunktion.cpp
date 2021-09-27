double my_func(double x, int n) {
    int ergebnis = x;
    int i = 1;
    while (i <= n) {
	ergebnis = ergebnis * x ;
        i = i + 1;
    } 
    return ergebnis;
}

int main() {
    double ergebnis1 = my_func(3.142, 4);
    double ergebnis2 = my_func(ergebnis1, 2);
    double ergebnis3 = my_func(5.0 + my_func(3.0, 2), 3);
    return 0;
}
