//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDEXPRESSION_H
#define FISH_ADDEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class AddExpression : public Symbol{
    using AddExpressionUP = std::unique_ptr<AddExpression>;
protected:

public:
    void execute() override;
};


#endif //FISH_ADDEXPRESSION_H
