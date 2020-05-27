//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_OREXPRESSION_H
#define FISH_OREXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class OrExpression : public Symbol{
    using OrExpressionUP = std::unique_ptr<OrExpression>;
protected:

public:
    void execute() override;
};


#endif //FISH_OREXPRESSION_H
