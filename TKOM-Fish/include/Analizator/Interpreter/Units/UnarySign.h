//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNARYSIGN_H
#define FISH_UNARYSIGN_H


#include <Analizator/Interpreter/Symbol.h>

class UnarySign : public Symbol{
    using UnarySignUP = std::unique_ptr<UnarySign>;
protected:

public:
    void execute() override;
};


#endif //FISH_UNARYSIGN_H
