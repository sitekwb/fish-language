//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEOPERATOR_H
#define FISH_RELATIVEOPERATOR_H


#include <Analizator/Interpreter/Symbol.h>

class RelativeOperator : public Symbol{
    using RelativeOperatorUP = std::unique_ptr<RelativeOperator>;
protected:

public:
    void execute() override;
};


#endif //FISH_RELATIVEOPERATOR_H
