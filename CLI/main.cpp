#include <iostream>
#include <iomanip>

// This is a very basic implamentation
// this SHOULD handle the math properly

float amount = 0.0f;
float price  = 0.0f;

int main(int argc, char** argv) {
    
    std::cout << "Input amount: ";

    while (std::cin >> amount) {
        if (amount <= 0.0f) {
            std::cout << std::endl << "Invalid amount.";
            break;
        }

        std::cout << std::endl << "Input price: ";
        while (std::cin >> price) {
            if (price <= 0.0f) {
                std::cout << std::endl << "Invalid price.";
                break;
            }

            if (price >= 10.0f) {
                std::cout << std::endl << "WLS after selling: " << ((amount / 200) * price);
                break;
            } else {
                std::cout << std::endl << "WLS after selling: " << (amount / price);
                break;
            }
        }
    }

    return 0;
}