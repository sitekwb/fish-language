//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IFSTATEMENT_H
#define FISH_IFSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class IfStatement : public Symbol{
    using IfStatementUP = std::unique_ptr<IfStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_IFSTATEMENT_H
