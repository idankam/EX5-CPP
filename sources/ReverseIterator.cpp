#include "ReverseIterator.hpp"

namespace ariel {

    // constractor:
    ReverseIterator::ReverseIterator(NodeObject * pointer) : Iterator(pointer) {
        if (pointer != nullptr) {
            _nodesStack.push(pointer);
            pushNodeObjectKids(pointer);

            while (!_nodesQueue.empty()) {
                NodeObject *nodeObg = this->_nodesQueue.front();
                _nodesStack.push(this->_nodesQueue.front());
                _nodesQueue.pop();
                pushNodeObjectKids(nodeObg);
            }
            setPointer(_nodesStack.top());
            _nodesStack.pop();
        }
    }
    // operator:

    ReverseIterator &ReverseIterator::operator++() {
        if (!_nodesStack.empty()) {
            setPointer(_nodesStack.top());
            _nodesStack.pop();
        } else {
            setPointer(nullptr);
        }

        return *this;
    }
    
    // add kids:
    void ReverseIterator::pushNodeObjectKids(NodeObject *nodeObg) {
        if (!nodeObg->getKids().empty()) {
            const vector<NodeObject *> kids = nodeObg->getKids();
            auto startObj = kids.crbegin();
            auto endObj = kids.crend();
            for (; startObj != endObj; ++startObj) {
                _nodesQueue.push(*startObj);
            }
        }
    }
}