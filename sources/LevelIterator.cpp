#include "LevelIterator.hpp"

namespace ariel {

    // constractor:
    LevelIterator::LevelIterator(NodeObject * pointer) : Iterator(pointer) {
        if (pointer != nullptr) {
            this->pushNodeObjectKid();
        }
    }

    // operator:
    LevelIterator &LevelIterator::operator++() {
        if (!_nodesQueue.empty()) {

            setPointer(_nodesQueue.front());
            _nodesQueue.pop();
            this->pushNodeObjectKid();
        } else {
            setPointer(nullptr);
        }

        return *this;
    }
    
    // add kids level:
    void LevelIterator::pushNodeObjectKid() {
        if (!getPointer()->getKids().empty()) {
            for (NodeObject * kid: getPointer()->getKids()) {
                _nodesQueue.push(kid);
            }
        }
    }
}
