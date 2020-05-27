//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENT_H
#define FISH_ARGUMENT_H


#include <Analizator/Interpreter/Symbol.h>

class Argument: public Symbol{
    using ArgumentUP = std::unique_ptr<Argument>;
protected:

public:
    void execute() override;
};


#endif //FISH_ARGUMENT_H
