//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNOPERATOR_H
#define FISH_ASSIGNOPERATOR_H


#include <Analizator/Symbol.h>

class AssignOperator: public Symbol{
protected:
    TokenUPD assignOperator;
    std::string value;
public:
    AssignOperator();
    void execute() override;
    const std::string &getValue() const;
};
using AssignOperatorUP = std::unique_ptr<AssignOperator>;

#endif //FISH_ASSIGNOPERATOR_H
