//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ANDEXPRESSION_H
#define FISH_ANDEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class AndExpression : public Symbol{
    using AndExpressionUP = std::unique_ptr<AndExpression>;
protected:

public:
    void execute() override;
};

#endif //FISH_ANDEXPRESSION_H
