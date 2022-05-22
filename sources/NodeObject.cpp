#include "NodeObject.hpp"
#include <iostream>

namespace ariel {

    // constractors:
    NodeObject::NodeObject() {}
    NodeObject::NodeObject(const string &name) : _name(name) {}
    NodeObject::NodeObject(const string &name, const vector<NodeObject *> &kids) : _name(name), _kids(kids) {}

    size_t NodeObject::size() {
        return this->_name.size();
    }  

    ostream &operator<<(ostream &outputStream, const NodeObject &currNodeObject) {
        outputStream << currNodeObject._name << " ";
        return outputStream;
    }

    const vector<NodeObject *> &NodeObject::getKids() const {
        return _kids;
    }

    const string &NodeObject::getName() const {
        return _name;
    }

    void NodeObject::addKid(NodeObject *newChild) {
        this->_kids.push_back(newChild);
    }

    void NodeObject::setName(const string &name) {
        _name = name;
    }

}