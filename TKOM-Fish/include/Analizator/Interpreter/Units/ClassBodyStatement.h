//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CLASSBODYSTATEMENT_H
#define FISH_CLASSBODYSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class ClassBodyStatement : public Symbol{
    using ClassBodyStatementUP = std::unique_ptr<ClassBodyStatement>;
protected:

public:
    void execute() override;
};


#endif //FISH_CLASSBODYSTATEMENT_H
