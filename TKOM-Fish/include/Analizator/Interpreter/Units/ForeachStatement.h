//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FOREACHSTATEMENT_H
#define FISH_FOREACHSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ForeachStatement : public Symbol{
    using ForeachStatementUP = std::unique_ptr<ForeachStatement>;
protected:

public:
    void execute() override;
};


#endif //FISH_FOREACHSTATEMENT_H
