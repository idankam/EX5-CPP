//
// Created by Eitan Kats on 12/05/2022.
//

#ifndef EX5_CPP_ORGCHARTLEVELITERATOR_HPP
#define EX5_CPP_ORGCHARTLEVELITERATOR_HPP

#include "Node.hpp"
#include "queue"
#include "OrgChartIterator.hpp"

namespace ariel {
    class OrgChartLevelIterator : public OrgChartIterator {

    private:
        using valueType = Node *;
        using reference = Node &;
        std::queue<valueType> currQueue;

        void push_node_children();

    public:
        OrgChartLevelIterator(valueType ptr);

        // Prefix increment
        OrgChartLevelIterator &operator++();

        // Postfix increment
        OrgChartLevelIterator operator++(int) {
            OrgChartLevelIterator tmp = *this;
            ++(*this);
            return tmp;
        }

    };
}


#endif //EX5_CPP_ORGCHARTLEVELITERATOR_HPP
