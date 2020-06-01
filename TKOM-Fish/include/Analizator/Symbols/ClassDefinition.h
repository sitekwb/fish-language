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
    ClassDefinition(ClassDefinition &cd);
    void executeConstructor(Env &env, ArgumentListUP &argumentList);
    void execute(Env &env) override;
    ObjectType getObjectType() const override;

};
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;


#endif //FISH_CLASSDEFINITION_H
