#ifndef ATOMNODE_HPP
#define ATOMNODE_HPP

#include "PRIORITY_TABLE.hpp"

class AtomNode {
    private:
        int prio;
    public:
        AtomNode();
        AtomNode(const std::string& element);
        int getPriority() const;
};

AtomNode::AtomNode() : prio(-1) {}
AtomNode::AtomNode(const std::string& element) {
    prio = PRIORITY_TABLE[element];
}
int AtomNode::getPriority() const {
    return prio;
}
#endif