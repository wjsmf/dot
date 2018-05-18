//
// Created by miles.shi on 2018/5/10.
//

#include <iostream>
#include "Wrapper.h"
double Wrapper::getWeight(ac a) const {
    switch (a){
        case AIE:
        case BIE:
            std::cout << "eeeee" << std::endl;
    }
    return weight;
}

void Wrapper::setWeight(double weight_) {
    weight = weight_;
}