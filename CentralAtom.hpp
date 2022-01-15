#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include <queue>
#include <iostream>
#include "AtomNode.hpp"
#include "ATOM_COMPARATOR.hpp"

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
    public:
        CentralAtom();
        ~CentralAtom();
        void buildBonds(
            const std::string& flat1,
            const std::string& flat2,
            const std::string& wedged,
            const std::string& dashed
        );
        AtomNode* getMinPriorityAtom();
        AtomNode* getFlat1() const;
        AtomNode* getFlat2() const;
        AtomNode* getDashed() const;
        AtomNode* getWedged() const;
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

// Pop and return pointer to min prio atom
AtomNode* CentralAtom::getMinPriorityAtom() {
    if (pq.top()->getPriority() == -1)
        return nullptr;
    AtomNode *minAtom = pq.top();
    return minAtom;
}

AtomNode* CentralAtom::getFlat1() const {
    return flat1;
}

AtomNode* CentralAtom::getFlat2() const {
    return flat2;
}

AtomNode* CentralAtom::getDashed() const {
    return dashed;
}

AtomNode* CentralAtom::getWedged() const {
    return wedged;
}

#endif