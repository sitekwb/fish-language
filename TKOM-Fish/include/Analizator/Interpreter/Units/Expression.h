//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSION_H
#define FISH_EXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class Expression : public Symbol{
    using ExpressionUP = std::unique_ptr<Expression>;
protected:

public:
    void execute() override;
};

#endif //FISH_EXPRESSION_H
