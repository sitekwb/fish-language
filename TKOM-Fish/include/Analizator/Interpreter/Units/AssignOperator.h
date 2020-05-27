//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNOPERATOR_H
#define FISH_ASSIGNOPERATOR_H


#include <Analizator/Interpreter/Symbol.h>

class AssignOperator: public Symbol{
    using AssignOperatorUP = std::unique_ptr<AssignOperator>;
protected:

public:
    void execute() override;
};

#endif //FISH_ASSIGNOPERATOR_H
