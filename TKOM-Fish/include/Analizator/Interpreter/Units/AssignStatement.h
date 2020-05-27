//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNSTATEMENT_H
#define FISH_ASSIGNSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class AssignStatement : public Symbol{
    using AssignStatementUP = std::unique_ptr<AssignStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_ASSIGNSTATEMENT_H
