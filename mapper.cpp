#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char ** argv) {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        std::string token;
        int column = 0;
        double price = 0.0;
        
        while (std::getline(ss, token, ',')) {
            if (column == 9) {
                try {
                    price = std::stod(token);
                    std::cout << "1\t" << price << "\t" << price * price << std::endl;
                } catch (...) { }
            }

            column++;
        }
    }

    return 0;
}