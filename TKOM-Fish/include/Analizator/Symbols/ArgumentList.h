//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENTLIST_H
#define FISH_ARGUMENTLIST_H


#include <Analizator/Symbol.h>
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
    ArgumentList(int);
    ArgumentList(ArgumentList &argumentList);
    void execute(Env &env) override;
    int getSize() const;
    friend class Test;
    friend class ArgumentList;
    ObjectType getObjectType() const override;
};
using ArgumentListUP = std::unique_ptr<ArgumentList>;

#endif //FISH_ARGUMENTLIST_H
