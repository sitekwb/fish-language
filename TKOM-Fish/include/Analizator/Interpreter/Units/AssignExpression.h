//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNEXPRESSION_H
#define FISH_ASSIGNEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class AssignExpression : public Symbol{
    using AssignExpressionUP = std::unique_ptr<AssignExpression>;
protected:

public:
    void execute() override;
};


#endif //FISH_ASSIGNEXPRESSION_H
