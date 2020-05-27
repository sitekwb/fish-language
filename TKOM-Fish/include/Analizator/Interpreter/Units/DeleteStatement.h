//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_DELETESTATEMENT_H
#define FISH_DELETESTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class DeleteStatement: public Symbol{
    using DeleteStatementUP = std::unique_ptr<DeleteStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_DELETESTATEMENT_H
