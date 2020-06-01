//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYOPERATOR_H
#define FISH_MULTIPLYOPERATOR_H


#include <Analizator/Symbol.h>

class MultiplyOperator: public Symbol{
protected:
    TokenUPD operatorToken;

public:
    MultiplyOperator();
    void execute(Env &env) override;
    int getInt() const override;
};
using MultiplyOperatorUP = std::unique_ptr<MultiplyOperator>;


#endif //FISH_MULTIPLYOPERATOR_H
