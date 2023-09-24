#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

bool isValidIBAN(const std::string& iban) {
    // checking iban length.
    //if (iban.length() != 22) {
    //    return false;
    //}

    // checking if there are any specific characters in the iban.
    for (char c : iban) {
        if (!std::isalnum(c)) {
            return false;
        }
    }

    std::string rearrangedIBAN = iban.substr(4) + iban.substr(0, 4);

    std::string convertedIBAN;

    for (char c: rearrangedIBAN){
        if(std::isdigit(c)){
            convertedIBAN += c;
        } else if (std::isalpha(c)){
            convertedIBAN += std::to_string(c - 'A' + 10);
        }
    }

    // the iban number does not fit into long long - therefore iteration
    int index = 1;
    unsigned long long digit = 0;
    unsigned long long leftover = 0;
    for (index = 0; index < convertedIBAN.length(); index++){
        digit = std::stoll(convertedIBAN.substr(index, 1));
        leftover = (10 * leftover + digit) % 97;
    }
    return leftover == 1; 
}

void toUpper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " IBAN" << std::endl;
        return EXIT_FAILURE;
    }

    toUpper(argv[1]);
    std::string iban = argv[1];

    if (isValidIBAN(iban)) {
        std::cout << "IBAN checksum is valid." << std::endl;
    } else {
        std::cout << "IBAN checksum is not valid." << std::endl;
    }

    return EXIT_SUCCESS;
}
