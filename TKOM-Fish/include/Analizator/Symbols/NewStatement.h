//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWSTATEMENT_H
#define FISH_NEWSTATEMENT_H


#include <Analizator/Symbol.h>
#include "NewExpression.h"

class NewExpression;
using NewExpressionUP = std::unique_ptr<NewExpression>;

class NewStatement : public Symbol{
protected:
    NewExpressionUP newExpression;
public:
    NewStatement();
    void execute(Env &env) override;
};
using NewStatementUP = std::unique_ptr<NewStatement>;

#endif //FISH_NEWSTATEMENT_H
