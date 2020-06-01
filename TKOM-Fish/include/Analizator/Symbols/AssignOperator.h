//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNOPERATOR_H
#define FISH_ASSIGNOPERATOR_H


#include <Analizator/Symbol.h>

class AssignOperator: public Symbol{
protected:
    TokenUPD assignOperator;
    //INTERP done
public:
    AssignOperator();
    void execute(Env &env) override;
    int getInt() const override;
    ObjectType getObjectType() const override;
};
using AssignOperatorUP = std::unique_ptr<AssignOperator>;

#endif //FISH_ASSIGNOPERATOR_H
