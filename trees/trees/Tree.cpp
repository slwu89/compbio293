//
//  Tree.cpp
//  trees
//
//  Created by Sean Wu on 9/13/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#include <iostream>
#include <set>
#include "Tree.hpp"
#include "RandomVariable.h"
#include "Node.hpp"

Tree::Tree(double lambda, double mu, double duration, RandomVariable* rv){
    
    // tree starts with 2 nodes
    root = addNode();
    Node* p = addNode(); // 2nd node

    root->addDescendant(p);
    root->setTime(0.0);
    
    p->setAncestor(root);
    
    // keep track of active nodes
    std::set<Node*> activeNodes;
    activeNodes.insert(p);
    
    
    double t = 0.0;
    // sim ends when overrun time or if the phylogeny dies out
    while(t < duration && activeNodes.size() > 0){
        
        // get the rate and sample when happens
        double rate = activeNodes.size()*(lambda+mu);
        t += rv->exponentialRv(rate);
        
        if(t < duration){
            
            // choose node to act upon
            int whichNode = (int)(rv->uniformRv() * activeNodes.size());
            int i = 0;
            for(std::set<Node*>::iterator it = activeNodes.begin(); it != activeNodes.end(); it++){
                if(i == whichNode){
                    p = (*it);
                    break;
                }
                i++;
            }
            
            // decide if it speciates or extinction event
            if(rv->uniformRv() < lambda / (lambda+mu)){
                //speciate
                Node* newNode1 = addNode();
                Node* newNode2 = addNode();
                p->addDescendant(newNode1);
                p->addDescendant(newNode2);
                newNode1->setAncestor(p);
                newNode2->setAncestor(p);
                p->setTime(t);
                activeNodes.erase(p);
                activeNodes.insert(newNode1);
                activeNodes.insert(newNode2);
            } else {
                //go extinct
                p->setTime(t);
                activeNodes.erase(p);
            }
            
            // do the event
            
        } // end action on each iteration
        
        
    } // end simulation loop
    
    // any nodes still active
    for(std::set<Node*>::iterator it = activeNodes.begin(); it != activeNodes.end(); it++){
        (*it)->setTime(duration);
    }
    
}

Node* Tree::addNode(void){
    
    if(nodes.size()> 1000000){
        std::cout << "Error: the tree is too big" << std::endl;
        exit(1);
    }
    
    Node* p = new Node;
    p->setIndex((int)nodes.size());
    nodes.push_back(p);
    
    return(p);
    
}
