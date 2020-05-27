//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNARYNOT_H
#define FISH_UNARYNOT_H


#include <Analizator/Interpreter/Symbol.h>

class UnaryNot : public Symbol{
    using UnaryNotUP = std::unique_ptr<UnaryNot>;
protected:

public:
    void execute() override;
};


#endif //FISH_UNARYNOT_H
