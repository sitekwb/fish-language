//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CLASSBODY_H
#define FISH_CLASSBODY_H


#include <Analizator/Interpreter/Symbol.h>

class ClassBody: public Symbol{
    using ClassBodyUP = std::unique_ptr<ClassBody>;
protected:

public:
    void execute() override;
};

#endif //FISH_CLASSBODY_H
