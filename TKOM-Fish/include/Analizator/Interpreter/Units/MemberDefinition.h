//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MEMBERDEFINITION_H
#define FISH_MEMBERDEFINITION_H


#include <Analizator/Interpreter/Symbol.h>

class MemberDefinition : public Symbol{
    using MemberDefinitionUP = std::unique_ptr<MemberDefinition>;
protected:

public:
    void execute() override;
};

#endif //FISH_MEMBERDEFINITION_H
