#ifndef ATOM_COMPARATOR_HPP
#define ATOM_COMPARATOR_HPP

#include "AtomNode.hpp"

class ATOM_COMPARATOR {
    public:
        int operator() (
            AtomNode *a1,
            AtomNode *a2
        );
};

int ATOM_COMPARATOR::operator() (
    AtomNode *a1,
    AtomNode *a2
) {
    return a1->getPriority() > a2->getPriority();
}

#endif