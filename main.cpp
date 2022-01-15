#include <iostream>
#include "PRIORITY_TABLE.hpp"
#include "CentralAtom.hpp"
#include "AtomNode.hpp"

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
    center.buildBonds(argv[1], argv[2], argv[3], argv[4]);
    AtomNode *minAtom = center.getMinPriorityAtom();
    if (!minAtom) {
        std::cout << "Error. Priority of bonding group is -1.\n";
        return 3;
    }
    // TODO: throw exception for minAtom == nullptr. Write rotate method and determine stereochemistry.
    return 0;
}