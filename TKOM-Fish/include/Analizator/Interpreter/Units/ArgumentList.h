//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENTLIST_H
#define FISH_ARGUMENTLIST_H


#include <Analizator/Interpreter/Symbol.h>

class ArgumentList : public Symbol{
    using ArgumentListUP = std::unique_ptr<ArgumentList>;
protected:

public:
    void execute() override;
};

#endif //FISH_ARGUMENTLIST_H
