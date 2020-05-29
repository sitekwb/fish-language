//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_CLASSDEFINITION_H
#define FISH_CLASSDEFINITION_H


#include <Analizator/Interpreter/Symbol.h>
#include "Type.h"
#include "ClassBody.h"

class ClassDefinition : public Symbol{
protected:
    TokenUPD classToken;
    TypeUP type;

    TokenUPD blockOpen;
    ClassBodyUP classBody;
    TokenUPD blockClose;
public:
    ClassDefinition();
    void execute() override;

};
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;


#endif //FISH_CLASSDEFINITION_H
