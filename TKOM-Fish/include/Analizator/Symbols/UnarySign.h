//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNARYSIGN_H
#define FISH_UNARYSIGN_H


#include <Analizator/Symbol.h>

class UnarySign : public Symbol{
protected:
    TokenUPD token;
public:
    UnarySign();
    void execute(Env &env) override;
    bool getBool()const override;
    ObjectType getObjectType() const override;
};
using UnarySignUP = std::unique_ptr<UnarySign>;


#endif //FISH_UNARYSIGN_H
