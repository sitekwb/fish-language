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
    std::list<std::reference_wrapper<Obj>> objectList;
public:
    ConditionalExpression();

    void execute(Env &env) override;

    double getDouble() const override;
    int getInt() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    Obj &getObject() override;
};

using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

#endif //FISH_CONDITIONALEXPRESSION_H
