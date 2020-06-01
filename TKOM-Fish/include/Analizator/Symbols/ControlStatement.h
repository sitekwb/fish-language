//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_CONTROLSTATEMENT_H
#define FISH_CONTROLSTATEMENT_H

#include <string>
#include <Analizator/Symbol.h>
#include "ConditionalExpression.h"

class ControlStatement : public Symbol{
protected:
    TokenUPD controlToken;
    ConditionalExpressionUP conditionalExpressionOptional;
    //INTERP done
public:
    ControlStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using ControlStatementUP = std::unique_ptr<ControlStatement>;


#endif //FISH_CONTROLSTATEMENT_H
