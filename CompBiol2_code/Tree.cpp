#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include "Node.h"
#include "RandomVariable.h"
#include "Tree.h"



Tree::Tree(double lambda, double mu, double duration, RandomVariable* rv) {

    /* This constructor builds a tree under the birth-death model of cladogenesis. */
    
    // initialize the beginning tree
    root = addNode();
    Node* p = addNode();
    p->setAncestor(root);
    root->addDescendant(p);
    root->setTime(0.0);
    
    // make a list of the "active" nodes that can speciate or go extinct
    std::set<Node*> activeNodes;
    activeNodes.insert(p);
    
    // make the b-d tree
    double t = 0.0;
    while (t < duration && activeNodes.size() > 0)
        {
        // get the rate
        double rate = activeNodes.size() * (lambda + mu);  // the rate is equal to the number of active lineages plus (speciation+extinction rates)
        t += rv->exponentialRv(rate);
        
        if (t < duration)
            {
            // Choose an active node to speciate or go extinct. Because all of the lineages have
            // the same rate of speciating or going extinct, the probability that a lineage is affected
            // is simply 1/(number of active lineages)
            int whichNode = (int)(rv->uniformRv() * activeNodes.size());
            int i = 0;
            for (std::set<Node*>::iterator it = activeNodes.begin(); it != activeNodes.end(); it++)
                {
                if (i == whichNode)
                    {
                    p = *it;
                    break;
                    }
                i++;
                }
            
            // decide whether it is a speciation or extinction event
            if ( rv->uniformRv() < lambda / (lambda+mu) )
                {
                // p speciates
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
                }
            else
                {
                // p goes extinct
                p->setTime(t);
                activeNodes.erase(p);
                }
            
            }
        
        }
    
    // simulation is finished
    for (std::set<Node*>::iterator it = activeNodes.begin(); it != activeNodes.end(); it++)
        {
        (*it)->setTime(duration);
        }
    
}

Node* Tree::addNode(void) {

    if (nodes.size() > 1000000)
        {
        std::cout << "Error: The tree has grown too large!" << std::endl;
        exit(1);
        }
    Node* p = new Node;
    p->setIndex( (int)nodes.size() );
    nodes.push_back(p);
    return p;
}

void Tree::initializeDownPassSequence(void) {

    downPassSequence.clear();
    passDown(root);
}

void Tree::passDown(Node* p) {

    if (p != NULL)
        {
        std::set<Node*> des = p->getDescendants();
        for (std::set<Node*>::iterator it = des.begin(); it != des.end(); it++)
            passDown(*it);
        downPassSequence.push_back(p);
        }
}

void Tree::showNodes(void) {

    showNodes(root, 0);
}

void Tree::showNodes(Node* p, int indent) {

    if (p != NULL)
        {
        std::set<Node*> des = p->getDescendants();
        
        for (int i=0; i<indent; i++)
            std::cout << " ";
        std::cout << p->getIndex();
        if (p->getAncestor() != NULL)
            std::cout << " " << p->getAncestor()->getIndex() << " ";
        else
            std::cout << " NULL ";
        std::cout << "( ";
        for (std::set<Node*>::iterator it = des.begin(); it != des.end(); it++)
            std::cout << (*it)->getIndex() << " ";
        std::cout << ") " << p->getTime();
        std::cout << std::endl;
        
        for (std::set<Node*>::iterator it = des.begin(); it != des.end(); it++)
            showNodes(*it, indent + 3);
        }
}

std::string Tree::getNewick(void) {

	std::stringstream ss;
	writeTree(root, ss);
	std::string newick = ss.str();
	return newick;
}


void Tree::writeTree(Node* p, std::stringstream& ss) {

	if (p != NULL)
		{
		if (p->numDescendants() == 0)
			{
			ss << p->getIndex() << ":" << std::fixed << std::setprecision(6) << p->getBranchLength();
			}
		else
			{
            ss << "(";
            std::set<Node*> myDescendants = p->getDescendants();
            int i = 0;
            for (std::set<Node*>::iterator it = myDescendants.begin(); it != myDescendants.end(); it++)
                {
                writeTree(*it, ss);
                if (i + 1 != myDescendants.size())
                    ss << ",";
                i++;
                }
            if (p == root)
                ss << ");";
            else
                ss << "):" << std::fixed << std::setprecision(6) << p->getBranchLength();
            }
		}
}
