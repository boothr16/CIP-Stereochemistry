#include <iostream>
#include "PRIORITY_TABLE.hpp"
#include "Tetrahedral.hpp"
#include "AtomNode.hpp"
#include "TrigonalProjection.hpp"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        std::cout << "Usage:"
        << " <flat atom 1> <flat atom 2> <wedged atom>"
        << " <dashed atom>\n";
        return 1;
    }
    Tetrahedral center;
    for (int i = 1; i < argc; i++) {
        std::string atom = argv[i];
        if (PRIORITY_TABLE.count(atom) == 0) {
            std::cout << "Incorrect atomic symbol"
            << " syntax or element not available.\n";
            return 2;
        }
    }
    center.buildBonds(argv[1], argv[2], argv[3], argv[4]);
    TrigonalProjection tp(center);
    std::cout << tp.GET_STEREOCHEMISTRY(center);
    return 0;
}