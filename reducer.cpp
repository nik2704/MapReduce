#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

int main(int argc, char ** argv) {
    std::string key;
    double sum = 0.0, sum_squares = 0.0;
    int count = 0;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        std::string token;
        double price, price_sq; //price_sq вычислили в маппере
        
        if (std::getline(ss, token, '\t')) { // всегда "1" - задали в маппере
            if (std::getline(ss, token, '\t')) { // цена
                price = std::stod(token);
                if (std::getline(ss, token, '\t')) { // цена * цена
                    price_sq = std::stod(token);
                    
                    count++;
                    sum += price;
                    sum_squares += price_sq;
                }
            }
        }
    }
    
    if (count > 0) {
        double mean = sum / count;
        double variance = (sum_squares / count) - (mean * mean);
        std::cout << "Средняя цена: " << mean << "\nДисперсия: " << variance << std::endl;
    }

    return 0;
}
