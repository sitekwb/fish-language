//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ImportStatement.h"

ImportStatement::ImportStatement() {
    constructed = buildToken("import", importToken)
            and buildToken(library);
    if(constructed and buildToken("as", asTokenOptional)){
        constructed = buildToken(library2);
    }
}

void ImportStatement::execute(Env &env) {
    lib = std::make_unique<Lib>(library->getValue());
    env.setSymbol((library2)?library2->getValue():library->getValue(), *lib);
}

ObjectType ImportStatement::getObjectType() const {
    return ObjectType::OT_ImportStatement;
}

