//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CLASSBODYSTATEMENT_H
#define FISH_CLASSBODYSTATEMENT_H


#include <Analizator/Symbol.h>
#include "FunctionDefinition.h"
#include "MemberDefinition.h"

class ClassBodyStatement : public Symbol{
protected:
    MemberDefinitionUP memberDefinition;
    FunctionDefinitionUP functionDefinition;
public:
    ClassBodyStatement();
    std::pair<std::string, Symbol&> getClassBodyStatementSymbol();
    void execute(Env &env) override;

};
using ClassBodyStatementUP = std::unique_ptr<ClassBodyStatement>;


#endif //FISH_CLASSBODYSTATEMENT_H
