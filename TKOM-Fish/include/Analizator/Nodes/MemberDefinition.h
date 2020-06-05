//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MEMBERDEFINITION_H
#define FISH_MEMBERDEFINITION_H

#include <string>
#include <list>
#include "ClassStatement.h"

enum class MBP {
    MB_PUBLIC,
    MB_PRIVATE,
    MB_SECRET,
};

class MemberDefinition : public ClassStatement {
protected:
    MBP memberDefinitionPublic;
    bool mutBool = false, staticBool = false;
    std::string typeNameOpt, idName;
public:
    MemberDefinition(MBP memberDefinitionPublic,
                     bool mutBool, bool staticBool,
                     std::string &&typeNameOpt,
                     std::string &&idName);
};

using MemberDefinitionUP = std::unique_ptr<MemberDefinition>;

#endif //FISH_MEMBERDEFINITION_H
