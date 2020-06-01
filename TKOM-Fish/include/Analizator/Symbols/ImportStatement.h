//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IMPORTSTATEMENT_H
#define FISH_IMPORTSTATEMENT_H


#include <Analizator/Symbol.h>
#include <Analizator/Interpreter/Lib.h>

class ImportStatement : public Symbol{
protected:
    TokenUPD importToken;
    IdentifierUPD library;
    TokenUPD asTokenOptional;
    IdentifierUPD library2;
    // INTERPRETER
    LibUP lib;
public:
    ImportStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
};
using ImportStatementUP = std::unique_ptr<ImportStatement>;

#endif //FISH_IMPORTSTATEMENT_H
