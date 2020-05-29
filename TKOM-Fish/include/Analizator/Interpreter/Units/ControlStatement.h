//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_CONTROLSTATEMENT_H
#define FISH_CONTROLSTATEMENT_H

#include <string>
#include <Analizator/Interpreter/Symbol.h>

class ControlStatement : public Symbol{
protected:
    TokenUPD controlToken;
public:
    ControlStatement();
    void execute() override;
};
using ControlStatementUP = std::unique_ptr<ControlStatement>;


#endif //FISH_CONTROLSTATEMENT_H
