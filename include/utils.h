/*
This header files declares small inline utility functions.
*/

#include <string>
#include <cctype>

#ifndef UTILS_H
#define UTILS_H

// overwrites non-whitespace characters
inline void trimWhitespaces(char* str){
    char* writePointer = str;
    while (*str){
        if(!std::isspace(static_cast<unsigned char>(*str)))
        {
            *writePointer = *str;
            ++writePointer;
        }
        ++str;
    }
    *writePointer = '\0';
}

// converts to upper
inline void toUpper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// converts to lower
inline void toLower(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

#endif //UTILS_H