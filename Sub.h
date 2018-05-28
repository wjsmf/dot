//
// Created by miles.shi on 2018/5/28.
//

#ifndef DOT_SUB_H
#define DOT_SUB_H


#include <iostream>
#include "Supere.h"

class Sub : public Supere{
public: void doit(){
        std::cout << age  << std::endl;
    }
};


#endif //DOT_SUB_H
