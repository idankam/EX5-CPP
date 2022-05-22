#ifndef REVERSEITERATOR
#define REVERSEITERATOR

#include <stack>
#include <queue>
#include <iostream>
#include "NodeObject.hpp"
#include "Iterator.hpp"

namespace ariel {

    class ReverseIterator : public Iterator {

    private:
        queue<NodeObject *> _nodesQueue;
        stack<NodeObject *> _nodesStack;
        void pushNodeObjectKids(NodeObject *);

    public:
        ReverseIterator(NodeObject * pointer);

        // increments:
        ReverseIterator &operator++();
        ReverseIterator operator++(int) {
            ReverseIterator tmpIter = *this;
            ++(*this);

            return tmpIter;
        }
    };
}

#endif
