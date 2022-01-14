#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include "AtomNode.hpp"

class CentralAtom {
    private:
        AtomNode *flat1;
        AtomNode *flat2;
        AtomNode *dashed;
        AtomNode *wedged;
        void setFlat1(const std::string& symbol);
        void setFlat2(const std::string& symbol);
        void setDashed(const std::string& symbol);
        void setWedged(const std::string& symbol);
    public:
        CentralAtom();
        ~CentralAtom();
        void buildBonds(
            const std::string& flat1,
            const std::string& flat2,
            const std::string& dashed,
            const std::string& wedged
        );
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

void CentralAtom::buildBonds(
            const std::string& flat1,
            const std::string& flat2,
            const std::string& dashed,
            const std::string& wedged
        ) {
            setFlat1(flat1);
            setFlat2(flat2);
            setDashed(dashed);
            setWedged(wedged);
        }

#endif