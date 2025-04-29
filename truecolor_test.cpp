#include <iostream>

int main() {
    for (int i = 0; i < 256; ++i) {
        std::cout << "\033[38;5;" << i << "m"
                  << "Color " << i << "\t";
        if ((i + 1) % 6 == 0)
            std::cout << "\n";
    }
    std::cout << "\033[0m" << std::endl;
    return 0;
}

//g++ truecolor_test.cpp -o testcolor && ./testcolor
