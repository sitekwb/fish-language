//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWSTATEMENT_H
#define FISH_NEWSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class NewStatement : public Symbol{
    using NewStatementUP = std::unique_ptr<NewStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_NEWSTATEMENT_H
