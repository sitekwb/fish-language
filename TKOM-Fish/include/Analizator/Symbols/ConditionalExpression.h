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

    //INTERPRETER
    std::list<Object &> objectList;
public:
    ConditionalExpression();

    void execute(Env &env) override;

    double getDouble() const;
    int getInt() const;
    std::string getString() const;
    bool getBool() const;
    ObjectType getObjectType() const;
    Object &getObject();
};

using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

#endif //FISH_CONDITIONALEXPRESSION_H
