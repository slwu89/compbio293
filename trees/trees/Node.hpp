//
//  Node.hpp
//  trees
//
//  Created by Sean Wu on 9/13/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <set>

class Node{

public:
    
                        Node(void);
    
    void                addDescendant(Node* p){ descendants.insert(p);}
    void                removeDescendant(Node* p){ descendants.erase(p);}
    std::set<Node*>     getDescendants(void){ return(descendants);}
    
    void                setIndex(int x){index = x;}
    int                 getIndex(void){return(index);}
    
    
    Node*               getAncestor(void){return(ancestor);}
    void                setAncestor(Node* p){ ancestor = p; }
    
    void                setTime(double x){time = x;}
    double              getTime(void){return(time);}
    
private:
    
    std::set<Node*>     descendants;
    int                 index;
    Node*               ancestor;
    double              time;
    
    
};


#endif /* Node_hpp */
