//
// Created by miles.shi on 2018/5/16.
//

#ifndef DOT_FEWSTRINGENUM_H
#define DOT_FEWSTRINGENUM_H


#include <string>

class Season {
    Season(std::string ass):string(ass){}
    Season(const Season& en);
    std::string string;
public:
    static const Season& SPRING;
    static const Season& SUMMER;
    static const Season& AUTUAM;
    static const Season& WINTER;

    const std::string &getString() const;

    void disappear(const Season& season)const {

    }

    void disappear(const Season& season) {

    }

    void disappear( Season& season) {

    }

    void disappear( Season& season)const {

    }

};


#endif //DOT_FEWSTRINGENUM_H
