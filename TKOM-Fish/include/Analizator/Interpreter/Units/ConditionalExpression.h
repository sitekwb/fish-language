//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CONDITIONALEXPRESSION_H
#define FISH_CONDITIONALEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class ConditionalExpression : public Symbol{
    using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;
protected:

public:
    void execute() override;
};

#endif //FISH_CONDITIONALEXPRESSION_H
