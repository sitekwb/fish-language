//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MEMBERDEFINITION_H
#define FISH_MEMBERDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ArgumentList.h"

class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;

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
    std::string getName();
    MemberDefinition();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    std::string getName() const;
};
using MemberDefinitionUP = std::unique_ptr<MemberDefinition>;

#endif //FISH_MEMBERDEFINITION_H
