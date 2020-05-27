//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IMPORTSTATEMENT_H
#define FISH_IMPORTSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ImportStatement : public Symbol{
    using ImportStatementUP = std::unique_ptr<ImportStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_IMPORTSTATEMENT_H
