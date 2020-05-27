//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_WHILESTATEMENT_H
#define FISH_WHILESTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class WhileStatement : public Symbol{
    using WhileStatementUP = std::unique_ptr<WhileStatement>;
protected:

public:
    void execute() override;
};


#endif //FISH_WHILESTATEMENT_H
