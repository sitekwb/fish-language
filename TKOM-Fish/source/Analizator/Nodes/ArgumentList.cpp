//
// Created by Wojtek on 27/05/2020.
//


#include <Analizator/Nodes/ArgumentList.h>

using namespace std;

ArgumentList::ArgumentList(std::list<ArgumentUP> &&argumentList)
        : argumentList(move(argumentList)) {

}