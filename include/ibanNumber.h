/*
This header declares ibanNumber class, its attributes and its methods.
*/

#include <string>
#include <unordered_map>

#ifndef IBAN_NUMBER_H
#define IBAN_NUMBER_H

class ibanNumber{
    public:
    ibanNumber(const std::string& iban, const std::string& country);
    // setters
    void setIBAN(const std::string newIBAN);
    void setCountry(const std::string newCountry);

    // getters
    std::string getIBAN();
    std::string getCountry();

    // validations
    bool isValidLength();
    bool isValidCountry();
    bool isValidCharacter();
    bool isValidCheckSum();

    private:
    std::string iban;
    std::string country;

    static const std::unordered_map<std::string, int> lengthMap;
};


#endif //IBAN_NUMBER_H