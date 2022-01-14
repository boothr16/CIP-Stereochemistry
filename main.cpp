#include <iostream>
#include "PRIORITY_TABLE.hpp"
#include "CentralAtom.hpp"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        std::cout << "Usage:"
        << " <flat atom 1> <flat atom 2> <dashed atom>"
        << " <wedged atom>\n";
        return 1;
    }
    CentralAtom center;
    for (int i = 1; i < argc; i++) {
        std::string atom = argv[i];
        if (PRIORITY_TABLE.count(atom) == 0) {
            std::cout << "Incorrect atomic symbol"
            << " syntax or element not available.\n";
            return 2;
        }
    }
    return 0;
}