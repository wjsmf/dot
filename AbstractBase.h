//
// Created by miles.shi on 2018/5/11.
//

#ifndef DOT_ABSTRACTBASE_H
#define DOT_ABSTRACTBASE_H


#include <ostream>

class AbstractBase {

    int a;
    AbstractBase(int aa):a(aa){}
    AbstractBase(){}

public:
     static const  AbstractBase* a1;

    virtual void show(){};

//    enum class i:long{AIE=1,BIE=5,CIE=2};
    friend std::ostream &operator<<(std::ostream &os, const AbstractBase &base) {
        os << "i: " << base.a;
        return os;
    }
};
#endif //DOT_ABSTRACTBASE_H
