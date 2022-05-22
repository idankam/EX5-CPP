#ifndef ORGCHART
#define ORGCHART

#include <iostream>
#include <unordered_map>

#include "NodeObject.hpp"
#include "LevelIterator.hpp"
#include "PreOrderIterator.hpp"
#include "ReverseIterator.hpp"

namespace ariel {

    class OrgChart {
    private:
        
        NodeObject *_rootNode;
        unordered_map<string, NodeObject *> _namesMap;
        void clearChart();

    public:

        // contractors:
        OrgChart();
        OrgChart(const OrgChart &chart2);
        ~OrgChart();

        // add:
        OrgChart &add_root(const string &rootNodeObject);
        OrgChart &add_sub(const string &father, const string &kid);
        
        // level iterator:
        LevelIterator begin();
        LevelIterator end();
        LevelIterator begin_level_order();
        LevelIterator end_level_order();

        // reverse iterator:
        ReverseIterator begin_reverse_order();
        ReverseIterator reverse_order();
        ReverseIterator end_reverse_order();

        // pre order iterator:
        PreOrderIterator begin_preorder();
        PreOrderIterator end_preorder();        

        // operators:
        OrgChart &operator=(OrgChart &chart2);
        friend ostream &operator<<(ostream &output, const OrgChart &chart);

    };
}

#endif