//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IMPORTSTATEMENT_H
#define FISH_IMPORTSTATEMENT_H


#include <Analizator/Interpreter/Lib.h>
#include "Statement.h"

class ImportStatement : public Statement{
protected:
    std::string libName, libAlias;
public:
    ImportStatement(std::string &&libName, std::string &&libAlias);
//    void initialize(Env &env);
//    void execute(Env &env) override;
};
using ImportStatementUP = std::unique_ptr<ImportStatement>;

#endif //FISH_IMPORTSTATEMENT_H
