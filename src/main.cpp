#include <iostream>
#include <string>
#include <cctype>

bool isValidIBAN(const std::string& iban) {

    // checking iban length.
    if (iban.length() != 22) {
        return false;
    }

    // checking if there are any specific characters in the iban.
    for (char c : iban) {
        if (!std::isalnum(c)) {
            return false;
        }
    }


    std::cout << iban << std::endl;
    std::string checkDigits = iban.substr(iban.length() - 2);
    std::string ibanBase = iban.substr(0, iban.length() - 2);

    // rearranging the iban to calculate modulo-97.
    std::string rearrangedIBAN = ibanBase.substr(4) + ibanBase.substr(0, 4);

    std::cout << rearrangedIBAN << std::endl;

    // performing modulo-97 checksum.
    unsigned long long remainder = 0;
    for (char c : rearrangedIBAN) {
        if (std::isdigit(c)) {
            remainder = (remainder * 10 + (c - '0')) % 97;
        } else if (std::isalpha(c)) {
            remainder = (remainder * 10 + (c - 'A' + 10)) % 97;
        }
    }

    std::cout << remainder << std::endl;
    return remainder == 1;
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
        std::cout << "IBAN is valid." << std::endl;
    } else {
        std::cout << "IBAN is not valid." << std::endl;
    }

    return EXIT_SUCCESS;
}
