//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IMPORTSTATEMENT_H
#define FISH_IMPORTSTATEMENT_H


#include <Analizator/Symbol.h>

class ImportStatement : public Symbol{
protected:
    TokenUPD importToken;
    IdentifierUPD library;
    TokenUPD asTokenOptional;
    IdentifierUPD library2;
public:
    ImportStatement();
    void execute() override;
};
using ImportStatementUP = std::unique_ptr<ImportStatement>;

#endif //FISH_IMPORTSTATEMENT_H
