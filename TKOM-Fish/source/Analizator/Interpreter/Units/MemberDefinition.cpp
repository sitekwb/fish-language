//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/MemberDefinition.h"

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

void MemberDefinition::execute() {
//TODO
}