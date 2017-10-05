#ifndef Node_h
#define Node_h

#include <set>


class Node {

    public:
                        Node(void);
        void            addDescendant(Node* p) { descendants.insert(p); }
        Node*           getAncestor(void) { return ancestor; }
        double          getBranchLength(void);
        std::set<Node*> getDescendants(void) { return descendants; }
        int             getIndex(void) { return index; }
        double          getTime(void) { return time; }
        int             numDescendants(void) { return (int)descendants.size(); }
        void            removeDescendant(Node* p) { descendants.erase(p); }
        void            setAncestor(Node* p) { ancestor = p; }
        void            setIndex(int x) { index = x; }
        void            setTime(double x) { time = x; }
    
    private:
        std::set<Node*> descendants;  // the list of descendant nodes
        Node*           ancestor;     // the ancestral node
        int             index;        // a variable simply there to distinguish nodes
        double          time;         // the time at which this node occurs
};

#endif
