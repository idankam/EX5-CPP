//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTITERATOR_HPP
#define EX5_CPP_ORGCHARTITERATOR_HPP

#include "Node.hpp"


namespace ariel {
    class OrgChartIterator {

    private:
        using valueType = Node *;
        using reference = Node &;
        valueType _ptr;

    protected:

        OrgChartIterator(valueType ptr) : _ptr(ptr) {

        }

    public:

        const Node *getPtr() const {
            return _ptr;
        }

        void setPtr(Node *ptr) {
            _ptr = ptr;
        };

        reference operator*() const { return *_ptr; }

        valueType operator->() { return _ptr; }

        bool operator==(const OrgChartIterator &b) const {
            return this->_ptr == b._ptr;
        }

        bool operator!=(const OrgChartIterator &b) const {
            return this->_ptr != b._ptr;
        }

        virtual OrgChartIterator &operator++() = 0;
    };
}


#endif //EX5_CPP_ORGCHARTITERATOR_HPP
