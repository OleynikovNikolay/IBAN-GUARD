
#include <string>
#include <unordered_map>
#include "../include/ibanNumber.h"

const std::unordered_map<std::string, int> ibanNumber::lengthMap = {
    {"AD", 24}, // Andorra
    {"AL", 28}, // Albania
    {"AT", 20}, // Austria
    {"BE", 16}, // Belgium
    {"BG", 22}, // Bulgaria
    {"CH", 21}, // Switzerland
    {"CY", 28}, // Cyprus
    {"CZ", 24}, // Czech Republic
    {"DE", 22}, // Germany
    {"DK", 18}, // Denmark
    {"EE", 20}, // Estonia
    {"ES", 24}, // Spain
    {"FI", 18}, // Finland
    {"FR", 27}, // France
    {"GB", 22}, // United Kingdom
    {"GR", 27}, // Greece
    {"HR", 21}, // Croatia
    {"HU", 28}, // Hungary
    {"IE", 22}, // Ireland
    {"IS", 26}, // Iceland
    {"IT", 27}, // Italy
    {"LT", 20}, // Lithuania
    {"LU", 20}, // Luxembourg
    {"LV", 21}, // Latvia
    {"MC", 27}, // Monaco
    {"MT", 31}, // Malta
    {"NL", 18}, // Netherlands
    {"NO", 15}, // Norway
    {"PL", 28}, // Poland
    {"PT", 25}, // Portugal
    {"RO", 24}, // Romania
    {"SE", 24}, // Sweden
    {"SI", 19}, // Slovenia
    {"SK", 24}  // Slovakia
};


ibanNumber::ibanNumber(const std::string& iban, const std::string& country)
    : iban(iban), country(country){
}

// validations
bool ibanNumber::isValidLength(){
    return lengthMap.find(country) != lengthMap.end() && lengthMap.at(country) == iban.length();
}

bool ibanNumber::isValidCharacter(){
    for (char c : iban) {
        if (!std::isalnum(c)) {
            return false;
        }
    }
    return true;
}

bool ibanNumber::isValidCountry(){
    return lengthMap.find(country) != lengthMap.end();
}

bool ibanNumber::isValidCheckSum(){
    std::string rearrangedIBAN = iban.substr(4) + iban.substr(0, 4);

    std::string convertedIBAN;

    for (char c: rearrangedIBAN){
        if(std::isdigit(c)){
            convertedIBAN += c;
        } else if (std::isalpha(c)){
            convertedIBAN += std::to_string(c - 'A' + 10);
        }
    }

    int digit = 0;
    int leftover = 0;
    for (int index = 0; index < convertedIBAN.length(); index++){
        digit = std::stoll(convertedIBAN.substr(index, 1));
        leftover = (10 * leftover + digit) % 97;
    }
    return leftover == 1; 
}