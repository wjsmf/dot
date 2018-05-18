//
// Created by miles.shi on 2018/5/16.
//

#include "Season.h"
 const Season& Season::SPRING{"SPRING"};
 const Season& Season::SUMMER{"SUMMER"};
 const Season& Season::AUTUAM{"AUTUAM"};
 const Season& Season::WINTER{"WINTER"};

const std::string &Season::getString() const {
    return string;
}
