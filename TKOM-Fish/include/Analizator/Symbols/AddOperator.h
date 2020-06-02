//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDOPERATOR_H
#define FISH_ADDOPERATOR_H


#include <Analizator/Symbol.h>

class AddOperator : public Symbol{
protected:
    TokenUPD operatorToken;
    //INTERPRETER done
public:
    AddOperator();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;

};
using AddOperatorUP = std::unique_ptr<AddOperator>;


#endif //FISH_ADDOPERATOR_H
