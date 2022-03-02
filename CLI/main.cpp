#include <iostream>
#include <iomanip>

// This is a very basic implamentation
// this SHOULD handle the math properly

int amount = 0;
float price  = 0.0f;

int main(int argc, char** argv) {

    static bool  SaveTotal  = false;
    static float SavedTotal = 0.0f;

    while (true) {

        float Amount     = 0.0f;
        float Price      = 0.0f;
        float Total      = 0.0f;

        std::cout << "Input Amount: ";
        std::cin >> Amount;
        std::cout << "Input Price: ";
        std::cin >> Price;

        if (Amount == Price) {
            Total = Price;
        } else if (Amount < Price){
            Total = Amount * Price;
        } else {
            Total = Amount / Price;
        }

        if (SavedTotal) {
            std::cout << "SavedTotal: " << SavedTotal + Total << std::endl;
        } else {
            std::cout << "Total: " << Total << std::endl;
        }

        char c;
        std::cout << "Save Total:  Y/N" << std::endl;
        while (std::cin >> c) {
            switch (c) {
                case 'Y': case 'y':
                    SavedTotal += Total;
                    SaveTotal = true;
                    break;

                case 'N': case 'n':
                    SavedTotal = 0;
                    SaveTotal = false;
                    break;

                default:
                    std::cout << "Save Total:  Y/N" << std::endl;
                    continue;
            }

            break;
        }

        std::cout << std::endl;
    }   
}