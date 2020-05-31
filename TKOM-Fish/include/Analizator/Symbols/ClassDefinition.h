//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_CLASSDEFINITION_H
#define FISH_CLASSDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ClassBody.h"

class ClassDefinition : public Symbol{
protected:
    TokenUPD classToken;
    TypeUP type;

    TokenUPD blockOpen;
    std::list<ClassBodyStatementUP> classBodyStatementList;
    TokenUPD blockClose;

    GlobalEnv symbols;
public:
    std::string getName();
    ClassDefinition();
    void execute(Env &env) override;

};
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;


#endif //FISH_CLASSDEFINITION_H
