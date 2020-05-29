//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENTLIST_H
#define FISH_ARGUMENTLIST_H


#include <Analizator/Interpreter/Symbol.h>
#include "Argument.h"

class Argument;
using ArgumentUP = std::unique_ptr<Argument>;

class ArgumentList : public Symbol{
protected:
    ArgumentUP argumentOptional;
    std::list<std::pair<TokenUPD, ArgumentUP>>repeatListOptional;
    bool buildRepeat();
public:
    ArgumentList();
    void execute() override;
};
using ArgumentListUP = std::unique_ptr<ArgumentList>;

#endif //FISH_ARGUMENTLIST_H
