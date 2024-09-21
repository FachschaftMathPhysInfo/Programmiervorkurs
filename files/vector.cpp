#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::vector<int> einvector;

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        einvector.push_back(rand());
    }
    std::cout << "An Index  0 steht " << einvector[0] << std::endl;
    std::cout << "An Index 42 steht " << einvector[42] << std::endl;
    std::cout << "An Index 99 steht " << einvector[99] << std::endl;

    // und nun alle werte auf 42 setzen ;-)
    int i = 0;
    while (i < einvector.size()) {
        einvector[i] = 42;
        i = i + 1;
    }
    std::cout << "An Index  0 steht nun " << einvector[0] << std::endl;
    std::cout << "An Index 42 steht nun " << einvector[42] << std::endl;
    std::cout << "An Index 99 steht nun " << einvector[99] << std::endl;

    return 0;
}
