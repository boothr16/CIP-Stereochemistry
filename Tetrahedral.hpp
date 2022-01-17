#ifndef TETRAHEDRAL_HPP
#define TETRAHEDRAL_HPP

#include <queue>
#include <iostream>
#include "AtomNode.hpp"
#include "ATOM_COMPARATOR.hpp"

// Tetrahedral API
class Tetrahedral {
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
        Tetrahedral();
        ~Tetrahedral();
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

#endif