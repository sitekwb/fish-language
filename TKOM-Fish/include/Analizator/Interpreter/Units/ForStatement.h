//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORSTATEMENT_H
#define FISH_FORSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ForStatement : public Symbol{
    using ForStatementUP = std::unique_ptr<ForStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_FORSTATEMENT_H
