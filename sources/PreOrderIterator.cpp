#include "PreOrderIterator.hpp"

namespace ariel {

    // constractor:
    PreOrderIterator::PreOrderIterator(NodeObject * pointer) : Iterator(pointer) {
        if (pointer != nullptr) {
            this->pushNodeObjectKid();
        }
    }

    // operator:
    PreOrderIterator &PreOrderIterator::operator++() {
        if (!_nodesStack.empty()) {
            setPointer(_nodesStack.top());
            _nodesStack.pop();
            this->pushNodeObjectKid();
        } else {
            setPointer(nullptr);
        }

        return *this;
    }

    // add kids level:
    void PreOrderIterator::pushNodeObjectKid() {
        if (!getPointer()->getKids().empty()) {
            const vector<NodeObject *> kids = getPointer()->getKids();
            auto startObj = kids.crbegin();
            auto endOnj = kids.crend();
            for (; startObj != endOnj; ++startObj) {
                _nodesStack.push(*startObj);
            }
        }
    }

    
}