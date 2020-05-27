//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_BOOL_H
#define FISH_BOOL_H


#include <Analizator/Interpreter/Symbol.h>

class Bool : public Symbol{
    using BoolUP = std::unique_ptr<Bool>;
protected:

public:
    void execute() override;
};


#endif //FISH_BOOL_H
