#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::vector<int> einvector= std::vector<int>(100);

    srand(time(NULL));

    int i = 0;
    while (i < 100) {
        einvector[i] = rand();
        i = i + 1;
    }

    std::cout << "An Index 0 steht " << einvector[0] << std::endl;
    std::cout << "An Index 42 steht " << einvector[42] << std::endl;
    std::cout << "An Index 99 steht " << einvector[99] << std::endl;

    return 0;
}
