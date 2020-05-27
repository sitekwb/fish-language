//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWEXPRESSION_H
#define FISH_NEWEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class NewExpression : public Symbol{
    using NewExpressionUP = std::unique_ptr<NewExpression>;
protected:

public:
    void execute() override;
};

#endif //FISH_NEWEXPRESSION_H
