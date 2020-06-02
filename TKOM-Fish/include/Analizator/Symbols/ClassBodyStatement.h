//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CLASSBODYSTATEMENT_H
#define FISH_CLASSBODYSTATEMENT_H


#include <Analizator/Symbol.h>
#include "FunctionDefinition.h"
#include "MemberDefinition.h"

class FunctionDefinition;
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;

class MemberDefinition;
using MemberDefinitionUP = std::unique_ptr<MemberDefinition>;


class ClassBodyStatement : public Symbol{
protected:
    MemberDefinitionUP memberDefinition;
    FunctionDefinitionUP functionDefinition;
public:
    ClassBodyStatement();
    void execute(Env &env) override;
    std::string getName() const;
    ObjectType getObjectType() const override;
};
using ClassBodyStatementUP = std::unique_ptr<ClassBodyStatement>;


#endif //FISH_CLASSBODYSTATEMENT_H
