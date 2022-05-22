#ifndef ITERATOR
#define ITERATOR

#include "NodeObject.hpp"

namespace ariel {
    class Iterator {

    private:
        // using ref = NodeObject &;
        // using val_type = NodeObject *;
        
        NodeObject * _pointer;

    protected:

        // constractor
        Iterator(NodeObject * pointer) : _pointer(pointer) {}

    public:

        // get:
        const NodeObject *getPointer() const {
            return _pointer;
        }

        // set:
        void setPointer(NodeObject *pointer) {
            _pointer = pointer;
        };


        // operators:

        NodeObject & operator*() const { return *_pointer; }

        NodeObject * operator->() { return _pointer; }

        bool operator==(const Iterator &iter2) const {
            return this->_pointer == iter2._pointer;
        }

        bool operator!=(const Iterator &iter2) const {
            return this->_pointer != iter2._pointer;
        }

        virtual Iterator &operator++() = 0;
    };
}

#endif
