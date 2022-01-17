#ifndef ATOMNODE_HPP
#define ATOMNODE_HPP

#include "PRIORITY_TABLE.hpp"

// AtomNode API
class AtomNode {
    private:
        int prio;
    public:
        AtomNode();
        AtomNode(const std::string& element);
        int getPriority() const;
};

#endif