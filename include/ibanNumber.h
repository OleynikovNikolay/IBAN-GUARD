/*
This header declares ibanNumber class, its attributes and its methods.
*/

#include <string>
#include <unordered_map>

#ifndef IBAN_NUMBER_H
#define IBAN_NUMBER_H

class ibanNumber{
    public:
    std::string iban;
    std::string country;
    ibanNumber(const std::string& iban, const std::string& country);
    
    // validations
    bool isValidLength();
    bool isValidCountry();
    bool isValidCharacter();
    bool isValidCheckSum();

    private:
    static const std::unordered_map<std::string, int> lengthMap;
};


#endif //IBAN_NUMBER_H