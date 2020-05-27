//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYEXPRESSION_H
#define FISH_MULTIPLYEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class MultiplyExpression : public Symbol{
    using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;
protected:

public:
    void execute() override;
};


#endif //FISH_MULTIPLYEXPRESSION_H
