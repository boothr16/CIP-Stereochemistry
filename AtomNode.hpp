#ifndef ATOMNODE_HPP
#define ATOMNODE_HPP

#include "PRIORITY_TABLE.hpp"

class AtomNode {
    private:
        const int prio;
    public:
        AtomNode();
        AtomNode(const std::string &element);
        getPriority();
};

AtomNode::AtomNode() : prio(-1) {}
AtomNode::AtomNode(const std::string &element) {
    prio = PRIORITY_TABLE[element];
}
AtomNode::getPriority() {
    return prio;
}
#endif