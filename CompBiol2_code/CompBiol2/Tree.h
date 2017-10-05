#ifndef Tree_h
#define Tree_h

#include <string>
#include <vector>
class Node;
class RandomVariable;



class Tree {

    public:
        Tree(double lambda, double mu, double duration, RandomVariable* rv);
        std::string         getNewick(void);
        Node*               getRoot(void) { return root; }
        void                showNodes(void);
        void                showNodes(Node* p, int indent);
    
    private:
        Tree(void) {}
        void                initializeDownPassSequence(void);
        void                passDown(Node* p);                          // a recursive function to initialize the traversal sequence of the tree
        Node*               addNode(void);                              // a helper function for adding nodes
        void                writeTree(Node* p, std::stringstream& ss);  // a recursive function to write the tree in Newick format
        std::vector<Node*>  nodes;                                      // the memory addresses of all of the nodes for this tree
        Node*               root;                                       // a pointer to the root of the tree
        std::vector<Node*>  downPassSequence;                           // the ordered memory addresses of the nodes in pre-order traversal sequence
};

#endif
