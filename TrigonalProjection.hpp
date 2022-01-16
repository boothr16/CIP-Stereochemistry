#ifndef TRIGONALPROJECTION_HPP
#define TRIGONALPROJECTION_HPP

#include <string>
#include <iostream>
#include "Tetrahedral.hpp"

// TrigonalProjection API
class TrigonalProjection {
    private:
        AtomNode *top, *left, *right, *min;
    public:
        TrigonalProjection(Tetrahedral& tetrahedral);
        std::string GET_STEREOCHEMISTRY(Tetrahedral& tetrahedral) const;
};

// TrigonalProjection Implementation
TrigonalProjection::TrigonalProjection(Tetrahedral& tetrahedral) {
    AtomNode *minAtom = tetrahedral.getMinPriorityAtom();
    if (minAtom == tetrahedral.getFlat1()) {
        top = tetrahedral.getWedged();
        left = tetrahedral.getFlat2();
        right = tetrahedral.getDashed();
    }
    else if (minAtom == tetrahedral.getFlat2()) {
        top = tetrahedral.getFlat1();
        left = tetrahedral.getWedged();
        right = tetrahedral.getDashed();
    }
    else if (minAtom == tetrahedral.getWedged()) {
        top = tetrahedral.getFlat1();
        left = tetrahedral.getDashed();
        right = tetrahedral.getFlat2();
    }
    else if (minAtom == tetrahedral.getDashed()) {
        top = tetrahedral.getFlat1();
        left = tetrahedral.getFlat2();
        right = tetrahedral.getWedged();
    }
    min = minAtom;
}

// Determines if TrigonalProjection is achiral, R, or S stereochemistry.
std::string TrigonalProjection::GET_STEREOCHEMISTRY(Tetrahedral& tetrahedral) const {
    AtomNode *prevAtom = min;
    std::string message;
    // 3 more atoms on priority queue (lowest priority atom already popped off from constructor call)
    for (int i = 0; i < 3; i++) {
        AtomNode *currAtom = tetrahedral.getMinPriorityAtom();
        if (currAtom->getPriority() == prevAtom->getPriority()) {
            message = "Not a stereocenter. Achiral due to two or more identical bonding groups.\n";
            return message;
        }
        prevAtom = currAtom;
    }
    tetrahedral.getMinPriorityAtom();
    // At this point, prevAtom is the highest priority atom
    if (prevAtom == top) {
        message = (left->getPriority() > right->getPriority()) ?
        "STEREOCHEMICAL CONFIGURATION: S\n" : "STEREOCHEMICAL CONFIGURATION: R\n";
        return message;
    }
    else if (prevAtom == left) {
        message = (right->getPriority() > top->getPriority()) ?
        "STEREOCHEMICAL CONFIGURATION: S\n" : "STEREOCHEMICAL CONFIGURATION: R\n";
        return message;        
    }
    else if (prevAtom == right) {
        message = (top->getPriority() > left->getPriority()) ?
        "STEREOCHEMICAL CONFIGURATION: S\n" : "STEREOCHEMICAL CONFIGURATION: R\n";
        return message;
    }
    return "Could not determine stereochemistry.\n";
}

#endif