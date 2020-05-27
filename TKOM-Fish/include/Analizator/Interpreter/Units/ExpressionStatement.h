//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSIONSTATEMENT_H
#define FISH_EXPRESSIONSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ExpressionStatement : public Symbol{
    using ExpressionStatementUP = std::unique_ptr<ExpressionStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_EXPRESSIONSTATEMENT_H
