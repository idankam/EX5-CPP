//
// Created by Eitan Kats on 14/05/2022.
//

#include "OrgChartPreOrderIterator.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {

    void OrgChartPreOrderIterator::push_node_children() {
        if (!getPtr()->getChildren().empty()) {
            const std::vector<Node *> children = getPtr()->getChildren();
            auto _reverse_start = children.crbegin();
            auto _reverse_end = children.crend();
            for (; _reverse_start != _reverse_end; ++_reverse_start) {
                currStack.push(*_reverse_start);
            }
        }
    }

    OrgChartPreOrderIterator::OrgChartPreOrderIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            this->push_node_children();
        }
    }

    OrgChartPreOrderIterator &OrgChartPreOrderIterator::operator++() {
        if (!currStack.empty()) {
            setPtr(currStack.top());
            currStack.pop();
            this->push_node_children();
        } else {
            setPtr(nullptr);
        }

        return *this;
    }
}