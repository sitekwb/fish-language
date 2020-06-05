//
// Created by Wojtek on 04/06/2020.
//

#ifndef FISH_PROPERTYASSIGNMENT_H
#define FISH_PROPERTYASSIGNMENT_H

#include <list>
#include <string>
#include "AssignStatement.h"

class PropertyAssignment : public Statement{
    std::list<std::string> idNameList;
    StatementUP assignStatement;
public:
    PropertyAssignment(std::list<std::string> &&idNameList, StatementUP &&assignStatement);
};


#endif //FISH_PROPERTYASSIGNMENT_H
