//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENTLIST_H
#define FISH_ARGUMENTLIST_H


#include "Argument.h"
#include <list>

class Argument;
using ArgumentUP = std::unique_ptr<Argument>;

class ArgumentList {
protected:
    std::list<ArgumentUP>argumentList;
public:
    ArgumentList(std::list<ArgumentUP>&&argumentList);
};
using ArgumentListUP = std::unique_ptr<ArgumentList>;

#endif //FISH_ARGUMENTLIST_H
