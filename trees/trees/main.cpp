//
//  main.cpp
//  trees
//
//  Created by Sean Wu on 9/13/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "RandomVariable.h"
#include "Node.hpp"
#include "Tree.hpp"

int main(int argc, const char * argv[]) {
    
    
    // UI
    double lambda       = 1.0;
    double mu           = 0.3;
    double duration     = 10.0;
    
    // need an rng
    RandomVariable rv;
    
    // make a tree
    Tree myTree(lambda, mu, duration, &rv);
    myTree.showNodes();

    
    std::cout << "test successful" << std::endl;
    std::cout << "tree has: " << myTree.numberOfNodes() << std::endl;
    return 0;
}
