//
// Created by Eitan Kats on 15/05/2022.
//

#ifndef EX5_CPP_ORGCHARTREVERSEITERATOR_HPP
#define EX5_CPP_ORGCHARTREVERSEITERATOR_HPP

#include "Node.hpp"
#include "stack"
#include "queue"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartReverseIterator : public OrgChartIterator {

    private:
        using valueType = Node *;
        using reference = Node &;
        std::stack<valueType> currStack;
        std::queue<valueType> currQueue;

        void push_node_children(valueType);

    public:
        OrgChartReverseIterator(valueType ptr);

        OrgChartReverseIterator &operator++();

        OrgChartReverseIterator operator++(int) {
            OrgChartReverseIterator tmp = *this;
            ++(*this);
            return tmp;
        }
    };
}


#endif //EX5_CPP_ORGCHARTREVERSEITERATOR_HPP
