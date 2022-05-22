//
// Created by Eitan Kats on 14/05/2022.
//

#ifndef EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
#define EX5_CPP_ORGCHARTPREORDERITERATOR_HPP

#include "stack"
#include "Node.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartPreOrderIterator : public OrgChartIterator {

    private:
        using valueType = Node *;
        using reference = Node &;

        std::stack<valueType> currStack;

        void push_node_children();

    public:
        OrgChartPreOrderIterator(valueType ptr);

        OrgChartPreOrderIterator &operator++();

        OrgChartPreOrderIterator operator++(int) {
            OrgChartPreOrderIterator tmp = *this;
            ++(*this);
            return tmp;
        }
    };
}


#endif //EX5_CPP_ORGCHARTPREORDERITERATOR_HPP
