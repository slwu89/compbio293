//
//  main.cpp
//  compbio293
//
//  Created by Sean Wu on 8/30/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>


// make a struct
struct Person{
    int age;
    int ssn;
};

//// make a class
//class PersonClass{
//    
//};

int main(int argc, const char * argv[]) {
    
    // print out args
    std::cout << "argc = " << argc << std::endl;
    for( size_t i=0; i<argc; i++){
        std::cout << "argv[" << i << "] = " << argv[i] <<  std::endl;
    }
    
    // make some variables and how much mem do they consume?
    int x = 0;
    std::cout << "an integer takes up this many bytes: " << sizeof(int) << std::endl;
    std::cout << "mem address of x: " << &x << std::endl;
    
    // variable to hold the memory address of x (pointer)
    int* xAddress = &x;
    std::cout << "mem address of xAddress: " << xAddress << std::endl;
    std::cout << "a pointer takes up this many bytes: " << sizeof(int*) << std::endl;
    
    // make a float or a double
    float y = 0.1;
    double z = 0.1;
    std::cout << "y (float): " << y << std::endl;
    std::cout << "a float takes up this many bytes: " << sizeof(float) << std::endl;
    std::cout << "z (double): " << z << std::endl;
    std::cout << "a double takes up this many bytes: " << sizeof(double) << std::endl;
    
    // look at precision of floating point arithmetic
    std::cout << std::fixed << std::setprecision(50) << "precision of float: " <<  y << std::endl;
    std::cout << std::fixed << std::setprecision(50) << "precision of double: " <<  z << std::endl;
    
    // also have bool, char
    
    // make an array
    int a[100];
    for(size_t i=0; i<100; i++){
        a[i]=0;
    }
    for(size_t i=0; i<100; i++){
        std::cout << i << " --- " << a[i] << " " << &a[i] << std::endl;
    }
    
    // make some people
    Person people[100];
    people[0].age = 27;
    people[0].ssn = 12345;
    for(size_t i=0; i<100; i++){
        std::cout << i << " --- " << &people[i] << std::endl;
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
