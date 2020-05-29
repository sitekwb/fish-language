//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CLASSBODY_H
#define FISH_CLASSBODY_H


#include <Analizator/Interpreter/Symbol.h>
#include "ClassBodyStatement.h"

class ClassBody: public Symbol{
protected:
    std::list<ClassBodyStatementUP> classBodyStatementList;
public:
    ClassBody();
    void execute() override;

};
using ClassBodyUP = std::unique_ptr<ClassBody>;

#endif //FISH_CLASSBODY_H
