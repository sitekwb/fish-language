//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNARYNOT_H
#define FISH_UNARYNOT_H


#include <Analizator/Symbol.h>

class UnaryNot : public Symbol{
protected:
    TokenUPD notToken;
public:
    UnaryNot();
    void execute(Env &env) override;
    bool getBool()const override;
};
using UnaryNotUP = std::unique_ptr<UnaryNot>;


#endif //FISH_UNARYNOT_H
