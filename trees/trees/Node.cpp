//
//  Node.cpp
//  trees
//
//  Created by Sean Wu on 9/13/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#include "Node.hpp"

Node::Node(void){
    time = 0.0;
    index = 0;
    ancestor = NULL;
}

double Node::getBranchLength(void){
    if(ancestor != NULL){
        return(
         time - ancestor->getTime()
        );
    } else {
        return(0.0);
    }
}
