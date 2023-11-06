#include <iostream>
#include "../include/utils.h"
#include "../include/command_handlers.h"

int main(int argc, char* argv[]) {

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " --command" << std::endl;
        return EXIT_FAILURE;
    }

    toLower(argv[1]);
    std::string command = argv[1];

    if(command == "--help"){
        showHelp();
    } else if (command == "--validate-iban"){
        validateIBAN(argv);
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
