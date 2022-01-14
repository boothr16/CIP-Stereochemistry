#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include "AtomNode.hpp"

class CentralAtom {
    private:
        AtomNode *flat1;
        AtomNode *flat2;
        AtomNode *dashed;
        AtomNode *wedged;
    public:
        CentralAtom();
        ~CentralAtom();
        void setFlat1(const std::string& symbol);
        void setFlat2(const std::string& symbol);
        void setDashed(const std::string& symbol);
        void setWedged(const std::string& symbol);
};

CentralAtom::CentralAtom() {
    flat1 = nullptr;
    flat2 = nullptr;
    dashed = nullptr;
    wedged = nullptr;
}

CentralAtom::~CentralAtom() {
    delete flat1;
    delete flat2;
    delete dashed;
    delete wedged;
}

void CentralAtom::setFlat1(const std::string& symbol) {
    flat1 = new AtomNode(symbol);
}

void CentralAtom::setFlat2(const std::string& symbol) {
    flat2 = new AtomNode(symbol);
}

void CentralAtom::setDashed(const std::string& symbol) {
    dashed = new AtomNode(symbol);
}

void CentralAtom::setWedged(const std::string& symbol) {
    wedged = new AtomNode(symbol);
}


#endif