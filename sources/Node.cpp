//
// Created by Eitan Kats on 11/05/2022.
//

#include "Node.hpp"
#include "iostream"

namespace ariel {

    Node::Node(const std::string &label) : _label(label) {}

    Node::Node(const std::string &label, const std::vector<Node *> &children) : _label(label), _children(children) {}

    size_t Node::size() {
        return this->_label.size();
    }

    Node::Node() {}


    std::ostream &operator<<(std::ostream &output, const Node &currNode) {
        output << currNode._label;
        return output;
    }

    const std::vector<Node *> &Node::getChildren() const {
        return _children;
    }

    const std::string &Node::getLabel() const {
        return _label;
    }

    void Node::add_child(Node *newChild) {
        this->_children.push_back(newChild);
    }

    void Node::setLabel(const std::string &label) {
        _label = label;
    }

}