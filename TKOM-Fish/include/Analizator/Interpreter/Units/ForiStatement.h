//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORISTATEMENT_H
#define FISH_FORISTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ForiStatement : public Symbol{
    using ForiStatementUP = std::unique_ptr<ForiStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_FORISTATEMENT_H
