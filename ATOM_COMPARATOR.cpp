#include "ATOM_COMPARATOR.hpp"

int ATOM_COMPARATOR::operator() (
    AtomNode *a1,
    AtomNode *a2
) {
    return a1->getPriority() > a2->getPriority();
}