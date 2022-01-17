#include "Tetrahedral.hpp"

// Tetrahedral Implementation
Tetrahedral::Tetrahedral() {
    flat1 = nullptr;
    flat2 = nullptr;
    dashed = nullptr;
    wedged = nullptr;
}

Tetrahedral::~Tetrahedral() {
    delete flat1;
    delete flat2;
    delete dashed;
    delete wedged;
}

void Tetrahedral::setFlat1(const std::string& symbol) {
    flat1 = new AtomNode(symbol);
    pq.push(flat1);
}

void Tetrahedral::setFlat2(const std::string& symbol) {
    flat2 = new AtomNode(symbol);
    pq.push(flat2);
}

void Tetrahedral::setDashed(const std::string& symbol) {
    dashed = new AtomNode(symbol);
    pq.push(dashed);
}

void Tetrahedral::setWedged(const std::string& symbol) {
    wedged = new AtomNode(symbol);
    pq.push(wedged);
}

void Tetrahedral::buildBonds(const std::string& flat1, 
const std::string& flat2, const std::string& wedged, const std::string& dashed) {
    setFlat1(flat1);
    setFlat2(flat2);
    setWedged(wedged);
    setDashed(dashed);
}

// Pop and return pointer to min priority atom
AtomNode* Tetrahedral::getMinPriorityAtom() {
    if (pq.top()->getPriority() == -1)
        return nullptr;
    AtomNode *minAtom = pq.top();
    pq.pop();
    return minAtom;
}

AtomNode* Tetrahedral::getFlat1() const {
    return flat1;
}

AtomNode* Tetrahedral::getFlat2() const {
    return flat2;
}

AtomNode* Tetrahedral::getDashed() const {
    return dashed;
}

AtomNode* Tetrahedral::getWedged() const {
    return wedged;
}