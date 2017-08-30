//
//  RandomVariable.hpp
//  compbio293
//
//  Created by Sean Wu on 8/30/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#ifndef RandomVariable_hpp
#define RandomVariable_hpp

#include <stdio.h>
#include <cstdint>

//enum {
//    N = 624;
//    M = 397;
//    R = 31;
//    A =
//};

class RandomVariable{
    
public:
    RandomVariable(void);
    RandomVariable(uint32_t seed);
    double uniformRv(void);
    
private:
    uint32_t extractU32(void);
    void initialize(uint32_t seed);
    void twist(void);
    uint16_t index;
    uint32_t mt[N];
    
};

#endif /* RandomVariable_hpp */
