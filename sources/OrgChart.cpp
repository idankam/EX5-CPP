//
// Created by Eitan Kats on 11/05/2022.
//

#include "OrgChart.hpp"
#include "OrgChartLevelIterator.hpp"
#include "iostream"
#include "stdexcept"
#include "queue"
#include "OrgChartReverseIterator.hpp"

namespace ariel {
    OrgChartLevelIterator OrgChart::begin() {
        return OrgChartLevelIterator(this->_root);
    }

    OrgChartLevelIterator OrgChart::end() {
        return OrgChartLevelIterator(nullptr);
    }

    OrgChartLevelIterator OrgChart::begin_level_order() {
        return OrgChartLevelIterator(this->_root);
    }

    OrgChartLevelIterator OrgChart::end_level_order() {
        return OrgChartLevelIterator(nullptr);
    }


    OrgChartPreOrderIterator OrgChart::begin_preorder() {
        return OrgChartPreOrderIterator(this->_root);
    }

    OrgChartPreOrderIterator OrgChart::end_preorder() {
        return OrgChartPreOrderIterator(nullptr);
    }

    OrgChartReverseIterator OrgChart::begin_reverse_order() {
        return OrgChartReverseIterator(this->_root);
    }

    OrgChartReverseIterator OrgChart::reverse_order() {
        return OrgChartReverseIterator(nullptr);
    }

    OrgChartReverseIterator OrgChart::end_reverse_order() {
        return OrgChartReverseIterator(nullptr);
    }

    OrgChart::OrgChart() : _root(nullptr) {}

    std::ostream &operator<<(std::ostream &output, const OrgChart &chart) {
        output << "BLA";
        return output;
    }

    OrgChart &OrgChart::add_root(const std::string &newRoot) {

        if (_root == nullptr) {
            Node *rootNode = new Node(newRoot);
            this->_root = rootNode;
        } else {
            std::string prevLabel = this->_root->getLabel();
            this->_root->setLabel(newRoot);
            this->labelMap.erase(prevLabel);
        }
        this->labelMap.insert({newRoot, this->_root});

        return *this;

    }

    OrgChart &OrgChart::add_sub(const std::string &existingElem, const std::string &newElem) {
        auto searchResult = this->labelMap.find(existingElem);
        if (searchResult != this->labelMap.end()) {
            Node *currNode = searchResult->second;
            Node *newChild = new Node(newElem);
            currNode->add_child(newChild);
            this->labelMap.insert({newElem, newChild});

        } else {
            throw std::invalid_argument("element doesn't exist");
        }
        return *this;
    }

    OrgChart::~OrgChart() {
        this->clearChart();
    }

    OrgChart &OrgChart::operator=(OrgChart &otherChart) {
        return *this;
    }

    OrgChart::OrgChart(const OrgChart &otherChart) {

    }

    void OrgChart::clearChart() {
        if (_root == nullptr) {
            return;
        }
        std::queue<Node *> clearingQueue;
        for (Node *child: this->_root->getChildren()) {
            clearingQueue.push(child);
        }
        delete this->_root;
        while (!clearingQueue.empty()) {
            Node *toClear = clearingQueue.front();
            clearingQueue.pop();
            for (Node *child: toClear->getChildren()) {
                clearingQueue.push(child);
            }
            delete toClear;
        }
    }

}