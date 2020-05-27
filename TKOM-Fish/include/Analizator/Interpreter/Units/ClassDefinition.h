//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_CLASSDEFINITION_H
#define FISH_CLASSDEFINITION_H


#include <Analizator/Interpreter/Symbol.h>

class ClassDefinition : public Symbol{
    using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;
protected:

public:
    void execute() override;
};


#endif //FISH_CLASSDEFINITION_H
