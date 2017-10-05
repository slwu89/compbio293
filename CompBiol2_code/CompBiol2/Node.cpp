#include "Node.h"




Node::Node(void) {

    time     = 0.0;
    index    = 0;
    ancestor = NULL;
}

double Node::getBranchLength(void) {

    if ( getAncestor() != NULL )
        {
        return time - ancestor->getTime();
        }
    return 0.0;
}
