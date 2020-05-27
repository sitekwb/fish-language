
//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_SIMPLESTATEMENT_H
#define FISH_SIMPLESTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class SimpleStatement : public Symbol{
    using SimpleStatementUP = std::unique_ptr<SimpleStatement>;
protected:

public:
    void execute() override;
};


#endif //FISH_SIMPLESTATEMENT_H
