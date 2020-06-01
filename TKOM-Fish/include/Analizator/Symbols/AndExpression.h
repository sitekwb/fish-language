//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ANDEXPRESSION_H
#define FISH_ANDEXPRESSION_H


#include <Analizator/Symbol.h>
#include "OrExpression.h"

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class AndExpression : public Symbol{
protected:
    OrExpressionUP orExpression;
    std::list<std::pair<TokenUPD,OrExpressionUP>> repeatList;

    bool buildRepeat();

    //INTERPRETER done
    std::list<std::reference_wrapper<Obj>>objectList;
public:
    AndExpression();
    void execute(Env &env) override;
    double getDouble() const override;
    int getInt() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    Obj &getObject() override;

    friend class Test;

};

using AndExpressionUP = std::unique_ptr<AndExpression>;
#endif //FISH_ANDEXPRESSION_H
