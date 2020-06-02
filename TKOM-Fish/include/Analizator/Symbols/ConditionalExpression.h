//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CONDITIONALEXPRESSION_H
#define FISH_CONDITIONALEXPRESSION_H


#include <Analizator/Symbol.h>
#include "AndExpression.h"

class AndExpression;

using AndExpressionUP = std::unique_ptr<AndExpression>;

class ConditionalExpression : public Symbol {
    AndExpressionUP andExpression;
    std::list<std::pair<TokenUPD, AndExpressionUP>> repeatList;

    bool buildRepeat();
    //INTERPRETER
public:
    ConditionalExpression();

    void execute(Env &env) override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
};

using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

#endif //FISH_CONDITIONALEXPRESSION_H
