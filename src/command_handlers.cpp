#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#include "../include/command_handlers.h"
#include "../include/utils.h"
#include "../include/ibanNumber.h"

// showing navigation panel
void showHelp(){
    std::cout << "Options:" << std::endl;
    std::cout << "  ./IBAN-GUARD                  [--help; --validate-iban]" << std::endl;
    std::cout << "  --help                        Shows navigation page." << std::endl;
    std::cout << "                                Usage: --help" << std::endl;
    std::cout << "  -validate-iban                Validates the IBAN number." << std::endl;
    std::cout << "                                Usage: --validate-iban iban_number" << std::endl;
}

// validating the iban
void validateIBAN(char* argv[]){
    toUpper(argv[2]);

    trimWhitespaces(argv[2]);

    std::string iban = argv[2];
    std::string country = iban.substr(0, 2);

    ibanNumber ibanObject(iban, country);

    bool validityLength = ibanObject.isValidLength();
    bool validityCharacter = ibanObject.isValidCharacter();
    bool validityCountry = ibanObject.isValidCountry();
    bool validityCheckSum = ibanObject.isValidCheckSum();

    if (!validityCharacter){
        std::cerr << "IBAN has invalid characters." << std::endl;
        return;
    }
    if (!validityCountry){
        std::cerr << "This IBAN country is not supported." << std::endl;
        return;
    }
    if (!validityLength){
        std::cerr << "IBAN length is not valid." << std::endl;
        return;
    }
    if (!validityCheckSum){
        std::cerr << "IBAN checksum is not valid." << std::endl;
        return;
    }

    std::cout << "IBAN is valid." << std::endl;

}