#ifndef ATOM_COMPARATOR_HPP
#define ATOM_COMPARATOR_HPP

#include "AtomNode.hpp"

// ATOM_COMPARATOR class passed to STL priority queue constructor to build MIN-heap of AtomNode pointers
class ATOM_COMPARATOR {
    public:
        int operator() (
            AtomNode *a1,
            AtomNode *a2
        );
};

#endif