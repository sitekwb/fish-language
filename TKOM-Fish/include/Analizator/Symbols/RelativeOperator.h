//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEOPERATOR_H
#define FISH_RELATIVEOPERATOR_H


#include <Analizator/Symbol.h>

class RelativeOperator : public Symbol{
protected:
    TokenUPD operatorToken;
    std::string value;
public:
    RelativeOperator();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
};
using RelativeOperatorUP = std::unique_ptr<RelativeOperator>;


#endif //FISH_RELATIVEOPERATOR_H
