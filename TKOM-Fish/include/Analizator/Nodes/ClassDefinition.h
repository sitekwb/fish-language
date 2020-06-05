//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_CLASSDEFINITION_H
#define FISH_CLASSDEFINITION_H

#include "ClassStatement.h"
#include <string>

class ClassDefinition {
protected:
    std::string typeName;
    std::list<ClassStatementUP>classStatementList;
public:
    ClassDefinition(std::string &&typeName,
                    std::list<ClassStatementUP> &&classStatementList);


};
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;


#endif //FISH_CLASSDEFINITION_H
