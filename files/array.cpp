#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int einarray[100];

    srand(time(NULL));

    int i = 0;
    while (i < 100) {
        einarray[i] = rand();
        i = i + 1;
    }

    std::cout << "An Index 0 steht " << einarray[0] << std::endl;
    std::cout << "An Index 42 steht " << einarray[42] << std::endl;
    std::cout << "An Index 99 steht " << einarray[99] << std::endl;

		return 0;
}
