#include <queue>
#include <iostream>
#include <stdexcept>

#include "OrgChart.hpp"

namespace ariel {

    // constractor:
    OrgChart::OrgChart() : _rootNode(nullptr) {}

    OrgChart::OrgChart(const OrgChart &chart2) {}

    // destractor:
    OrgChart::~OrgChart() {
        this->clearChart();
    }

    // set root:
    OrgChart &OrgChart::add_root(const string &rootName) {

        if (_rootNode == nullptr) {
            NodeObject *rootNode = new NodeObject(rootName);
            this->_rootNode = rootNode;
        } else {
            string previousName = this->_rootNode->getName();
            this->_rootNode->setName(rootName);
            this->_namesMap.erase(previousName);
        }
        this->_namesMap.insert({rootName, this->_rootNode});

        return *this;
    }

    // add elements:
    OrgChart &OrgChart::add_sub(const string &father, const string &kid) {
        auto find = this->_namesMap.find(father);
        if (find != this->_namesMap.end()) {
            NodeObject *nodeObj = find->second;
            NodeObject *newKid = new NodeObject(kid);
            nodeObj->addKid(newKid);
            this->_namesMap.insert({kid, newKid});

        }
        else {
            throw invalid_argument("object is not found!");
        }
        return *this;
    }

    // clean chart:
    void OrgChart::clearChart() {
        if (_rootNode == nullptr) {
            return;
        }
        queue<NodeObject *> deleteQ;
        for (NodeObject *kid: this->_rootNode->getKids()) {
            deleteQ.push(kid);
        }
        delete this->_rootNode;
        while (!deleteQ.empty()) {
            NodeObject *toDelete = deleteQ.front();
            deleteQ.pop();
            for (NodeObject *kid: toDelete->getKids()) {
                deleteQ.push(kid);
            }
            delete toDelete;
        }
    }

    // Level Iterator:

    LevelIterator OrgChart::begin() {
        return LevelIterator(this->_rootNode);
    }

    LevelIterator OrgChart::end() {
        return LevelIterator(nullptr);
    }

    LevelIterator OrgChart::begin_level_order() {
        return LevelIterator(this->_rootNode);
    }

    LevelIterator OrgChart::end_level_order() {
        return LevelIterator(nullptr);
    }

    // Pre Order Iterator:
    PreOrderIterator OrgChart::begin_preorder() {
        return PreOrderIterator(this->_rootNode);
    }

    PreOrderIterator OrgChart::end_preorder() {
        return PreOrderIterator(nullptr);
    }

    // Reverse Iterator:
    ReverseIterator OrgChart::begin_reverse_order() {
        return ReverseIterator(this->_rootNode);
    }

    ReverseIterator OrgChart::reverse_order() {
        return OrgChart::end_reverse_order();
    }

    ReverseIterator OrgChart::end_reverse_order() {
        return ReverseIterator(nullptr);
    }


    // operators:

    ostream &operator<<(ostream &outputStream, const OrgChart &chart) {
        outputStream << "...";
        return outputStream;
    }

    OrgChart &OrgChart::operator=(OrgChart &otherChart) {
        return *this;
    }

}