#include <iostream>
#include "Node.h"
#include "SimLAN.h"

int main()
{
    SimLAN _simLan;
    Node _node;
    Node _node1;
    _node.SubEvent(&_node1);
    _node1.SubEvent(&_node);
 /*
    _node1.GetSubscriptions();
    _node1.GetFollowers();
    _node.GetSubscriptions();
    _node.GetFollowers();
    */
    _node.UnSubEvent(&_node1);
    _node1.UnSubEvent(&_node);

    _node1.GetSubscriptions();
    _node1.GetFollowers();
    _node.GetSubscriptions();
    _node.GetFollowers();
   // std::cout << _simLan.Field.size();
 
}

