//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/MemberDefinition.h"

using namespace std;

MemberDefinition::MemberDefinition() {
    buildToken("public", publicToken)
    or buildToken("private", publicToken)
    or buildToken("secret", publicToken);

    buildToken("mut", mutToken);
    buildToken("static", staticToken);
    buildSymbol<Type>(type);
    constructed = buildToken(identifier);
    if(constructed and buildToken("(", bracketOpenOptional)){
        constructed = buildSymbol<ArgumentList>(argumentListOptional)
                and buildToken(")", bracketCloseOptional);
    }
}

void MemberDefinition::execute(Env &classSymbols) {
    // TODO mut, static etc
}

std::string MemberDefinition::getName() {
    return identifier->getValue();
}

ObjectType MemberDefinition::getObjectType() const {
    return ObjectType::OT_MemberDefinition;
}

std::string MemberDefinition::getName() const {
    return identifier->getValue();
}
