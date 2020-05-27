//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FUNCTIONCALL_H
#define FISH_FUNCTIONCALL_H


#include <Analizator/Interpreter/Symbol.h>

class FunctionCall: public Symbol{
    using FunctionCallUP = std::unique_ptr<FunctionCall>;
protected:

public:
    void execute() override;
};

#endif //FISH_FUNCTIONCALL_H
