//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MEMBERDEFINITION_H
#define FISH_MEMBERDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ArgumentList.h"

class MemberDefinition : public Symbol{
protected:
    TokenUPD publicToken;
    TokenUPD mutToken;
    TokenUPD staticToken;
    TypeUP type;
    IdentifierUPD identifier;
    TokenUPD bracketOpenOptional;
    ArgumentListUP argumentListOptional;
    TokenUPD bracketCloseOptional;
public:
    MemberDefinition();
    void execute() override;
};
using MemberDefinitionUP = std::unique_ptr<MemberDefinition>;

#endif //FISH_MEMBERDEFINITION_H
