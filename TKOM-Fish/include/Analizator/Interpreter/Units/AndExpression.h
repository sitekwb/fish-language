//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ANDEXPRESSION_H
#define FISH_ANDEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "OrExpression.h"

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class AndExpression : public Symbol{
protected:
    bool value;
    OrExpressionUP orExpression;
    std::list<std::pair<TokenUPD,OrExpressionUP>> repeatList;

    bool buildRepeat();
public:
    AndExpression();
    void execute() override;
    bool getValue();
};

using AndExpressionUP = std::unique_ptr<AndExpression>;
#endif //FISH_ANDEXPRESSION_H
