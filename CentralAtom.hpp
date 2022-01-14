#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include <string>
#include "AtomNode.hpp"

class CentralAtom {
    private:
        AtomNode *flat1;
        AtomNode *flat2;
        AtomNode *dashed;
        AtomNode *wedged;
    public:
        CentralAtom();
        void setFlat1(const std::string& symbol);
        void setFlat2(const std::string& symbol);
        void setDashed(const std::string& symbol);
        void setWedged(const std::string& symbol);
};

CentralAtom::CentralAtom() 
    : flat1("")
    , flat2("")
    , dashed("")
    , wedged("") {}


#endif