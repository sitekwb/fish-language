//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_BOOL_H
#define FISH_BOOL_H


#include <Analizator/Symbol.h>

class Bool : public Symbol{
protected:
    TokenUPD boolToken;
    bool value;
public:
    Bool();
    void execute(Env &env) override;
    bool getBool() const override;
};
using BoolUP = std::unique_ptr<Bool>;


#endif //FISH_BOOL_H
