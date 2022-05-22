#ifndef LEVELITERATOR
#define LEVELITERATOR

#include <queue>
#include "NodeObject.hpp"
#include "Iterator.hpp"

namespace ariel {
    
    class LevelIterator : public Iterator {

    private:
        queue<NodeObject *> _nodesQueue;
        void pushNodeObjectKid();

    public:
        LevelIterator(NodeObject * pointer);

        // increments:
        LevelIterator &operator++() override;
        LevelIterator operator++(int) {
            LevelIterator tmpIter = * this;
            ++(* this);

            return tmpIter;
        }
    };
}

#endif
