#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "../include/utils.h"
#include "../include/ibanNumber.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " IBAN" << std::endl;
        return EXIT_FAILURE;
    }

    toUpper(argv[1]);
    trimWhitespaces(argv[1]);

    std::string iban = argv[1];
    std::string country = iban.substr(0, 2);

    ibanNumber ibanObject(iban, country);

    bool validityLength = ibanObject.isValidLength();
    bool validityCharacter = ibanObject.isValidCharacter();
    bool validityCountry = ibanObject.isValidCountry();
    bool validityCheckSum = ibanObject.isValidCheckSum();

    if (!validityCharacter){
        std::cerr << "IBAN has invalid characters." << std::endl;
        return EXIT_FAILURE;
    }
    if (!validityCountry){
        std::cerr << "This IBAN country is not supported." << std::endl;
        return EXIT_FAILURE;
    }
    if (!validityLength){
        std::cerr << "IBAN length is not valid." << std::endl;
        return EXIT_FAILURE;
    }
    if (!validityCheckSum){
        std::cerr << "IBAN checksum is not valid." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "IBAN is valid." << std::endl;
    
    return EXIT_SUCCESS;
}
