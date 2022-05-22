#ifndef PREORDERITERATOR
#define PREORDERITERATOR

#include <stack>
#include "NodeObject.hpp"
#include "Iterator.hpp"

namespace ariel {

    class PreOrderIterator : public Iterator {

    private:

        stack<NodeObject *> _nodesStack;
        void pushNodeObjectKid();

    public:
        PreOrderIterator(NodeObject * pointer);

        // increments:
        PreOrderIterator &operator++();
        PreOrderIterator operator++(int) {
            PreOrderIterator tmpIter = *this;
            ++(*this);

            return tmpIter;
        }
    };
}

#endif
