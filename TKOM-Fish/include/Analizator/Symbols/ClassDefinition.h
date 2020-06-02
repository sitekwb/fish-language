//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_CLASSDEFINITION_H
#define FISH_CLASSDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ClassBodyStatement.h"
#include "ArgumentList.h"

class ClassBodyStatement;
using ClassBodyStatementUP = std::unique_ptr<ClassBodyStatement>;

class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;

class ClassDefinition : public Symbol{
protected:
    TokenUPD classToken;
    TypeUP type;

    TokenUPD blockOpen;
    std::list<ClassBodyStatementUP> classBodyStatementList;
    TokenUPD blockClose;

    //INTERPRETER
    Env symbols;
public:
    ClassDefinition();
    ClassDefinition(ClassDefinition &cd);
    void executeConstructor(Env &env, ArgumentListUP &argumentList);
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    std::string getName() const;
};
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;


#endif //FISH_CLASSDEFINITION_H
