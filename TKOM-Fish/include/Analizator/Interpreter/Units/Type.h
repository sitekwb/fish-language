//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_TYPE_H
#define FISH_TYPE_H


#include <Analizator/Interpreter/Symbol.h>

class Type : public Symbol{
protected:
    IdentifierUPD identifier;
public:
    Type();
    void execute() override;
};
using TypeUP = std::unique_ptr<Type>;

#endif //FISH_TYPE_H
