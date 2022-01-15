#ifndef TRIGONALPROJECTION_HPP
#define TRIGONALPROJECTION_HPP

#include <string>
#include <iostream>

struct TrigonalProjection {
    AtomNode *top, *left, *right;
    TrigonalProjection(CentralAtom *tetrahedral);
};

TrigonalProjection::TrigonalProjection(CentralAtom *tetrahedral) {
    AtomNode *minAtom = tetrahedral->getMinPriorityAtom();
    if (minAtom == tetrahedral->getFlat1()) {
        top = tetrahedral->getWedged();
        left = tetrahedral->getFlat2();
        right = tetrahedral->getDashed();
    }
    else if (minAtom == tetrahedral->getFlat2()) {
        top = tetrahedral->getFlat1();
        left = tetrahedral->getWedged();
        right = tetrahedral->getDashed();
    }
    else if (minAtom == tetrahedral->getWedged()) {
        top = tetrahedral->getFlat1();
        left = tetrahedral->getDashed();
        right = tetrahedral->getFlat2();
    }
    else if (minAtom == tetrahedral->getDashed()) {
        top = tetrahedral->getFlat1();
        left = tetrahedral->getFlat2();
        right = tetrahedral->getWedged();
    }
}

#endif