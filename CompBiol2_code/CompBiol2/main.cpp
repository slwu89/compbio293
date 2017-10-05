#include <iostream>
#include "RandomVariable.h"
#include "Tree.h"



int main(int argc, const char * argv[]) {

    // this is our user interface TODO: Maybe make this more user-friendly
    double lambda   = 0.6;
    double mu       = 0.1;
    double duration = 10.0;
    
    // instantiate our random number object
    RandomVariable rv;
    
    // make a tree under the birth-death model of cladogensis
    Tree myTree(lambda, mu, duration, &rv);
    myTree.showNodes();
    std::cout << myTree.getNewick() << std::endl;
    
    
    return 0;
}
