#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include <queue>
#include <iostream>
#include "AtomNode.hpp"
#include "ATOM_COMPARATOR.hpp"
#include "TrigonalProjection.hpp"

class CentralAtom {
    private:
        AtomNode *flat1, *flat2, *wedged, *dashed;
        void setFlat1(const std::string& symbol);
        void setFlat2(const std::string& symbol);
        void setDashed(const std::string& symbol);
        void setWedged(const std::string& symbol);
        // For O(1) access to least priority atom
        std::priority_queue<AtomNode*, std::vector<AtomNode*>,
        ATOM_COMPARATOR> pq;
        // For providing 2D abstraction
    public:
        CentralAtom();
        ~CentralAtom();
        void buildBonds(
            const std::string& flat1,
            const std::string& flat2,
            const std::string& wedged,
            const std::string& dashed
        );
        AtomNode* getMinPriorityAtom() const;
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
    pq.push(flat1);
}

void CentralAtom::setFlat2(const std::string& symbol) {
    flat2 = new AtomNode(symbol);
    pq.push(flat2);
}

void CentralAtom::setDashed(const std::string& symbol) {
    dashed = new AtomNode(symbol);
    pq.push(dashed);
}

void CentralAtom::setWedged(const std::string& symbol) {
    wedged = new AtomNode(symbol);
    pq.push(wedged);
}

void CentralAtom::buildBonds(const std::string& flat1, 
const std::string& flat2, const std::string& wedged, const std::string& dashed) {
    setFlat1(flat1);
    setFlat2(flat2);
    setDashed(wedged);
    setWedged(dashed);
}

// Return pointer to min prio atom
AtomNode* CentralAtom::getMinPriorityAtom() const {
    if (pq.top()->getPriority() == -1)
        return nullptr;
    return pq.top();
}

#endif