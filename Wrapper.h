//
// Created by miles.shi on 2018/5/10.
//

#ifndef DOT_WRAPPER_H
#define DOT_WRAPPER_H


#include "AbstractBase.h"

class Wrapper {
public:
    enum ac{AIE,BIE,CIE,DIE,EIE}; //枚举的最大好处是枚举是一种类型,而如果用static const int ac=3,则ac是整数,取值太宽泛缺乏枚举类型的约束
//    enum ac1:char{AIE,BIE,CIE,DIE,EIE};
    double getWeight(ac a) const;

    void setWeight(double weight);

private:

    double weight;

};

#endif //DOT_WRAPPER_H
