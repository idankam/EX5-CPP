//
// Created by Eitan Kats on 11/05/2022.
//

#ifndef EX5_CPP_NODE_HPP
#define EX5_CPP_NODE_HPP

#include "vector"
#include "string"

namespace ariel {

    class Node {
        std::string _label;
        std::vector<Node *> _children;

    public:
        const std::string &getLabel() const;

        Node();

        void setLabel(const std::string &label);

        const std::vector<Node *> &getChildren() const;

        Node(const std::string &label);

        Node(const std::string &label, const std::vector<Node *> &children);

        size_t size();

        void add_child(Node *newChild);

        friend std::ostream &operator<<(std::ostream &output, const Node &currNode);
    };
}


#endif //EX5_CPP_NODE_HPP
