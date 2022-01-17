#include "AtomNode.hpp"

// AtomNode Implementation
AtomNode::AtomNode() : prio(-1) {}

AtomNode::AtomNode(const std::string& element) {
    prio = PRIORITY_TABLE[element];
}

int AtomNode::getPriority() const {
    return prio;
}