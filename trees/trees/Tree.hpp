//
//  Tree.hpp
//  trees
//
//  Created by Sean Wu on 9/13/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <vector>
//#include "RandomVariable.h"
//#include "Node.hpp"

//this is an alternative way to include, its a forward declaration to the compiler
class Node;
class RandomVariable;

class Tree{
    
public:
    Tree(double lambda, double mu, double duration, RandomVariable* rv);
    Node*           getRoot(void){return(root);}
    Node*           addNode(void);
    int             numberOfNodes(void){return (int)nodes.size();}
    
private:
    std::vector<Node*>  nodes;
    Node*               root;
    
};

#endif /* Tree_hpp */
