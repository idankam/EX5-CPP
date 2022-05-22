//
// Created by Eitan Kats on 15/05/2022.
//

#include "OrgChartReverseIterator.hpp"
#include "iostream"

namespace ariel {
    void OrgChartReverseIterator::push_node_children(Node *currNode) {
        if (!currNode->getChildren().empty()) {
            const std::vector<Node *> children = currNode->getChildren();
            auto _reverse_start = children.crbegin();
            auto _reverse_end = children.crend();
            for (; _reverse_start != _reverse_end; ++_reverse_start) {
                currQueue.push(*_reverse_start);
            }
        }
    }

    OrgChartReverseIterator::OrgChartReverseIterator(valueType ptr) : OrgChartIterator(ptr) {
        if (ptr != nullptr) {
            currStack.push(ptr);
            push_node_children(ptr);

            while (!currQueue.empty()) {
                Node *currNode = this->currQueue.front();
                currStack.push(this->currQueue.front());
                currQueue.pop();
                push_node_children(currNode);
            }
            setPtr(currStack.top());
            currStack.pop();
        }
    }

    OrgChartReverseIterator &OrgChartReverseIterator::operator++() {
        if (!currStack.empty()) {
            setPtr(currStack.top());
            currStack.pop();
        } else {
            setPtr(nullptr);
        }

        return *this;
    }

}