//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNSIGNEDINTTERM_H
#define FISH_UNSIGNEDINTTERM_H


#include <Analizator/Interpreter/Symbol.h>

class UnsignedIntTerm : public Symbol{
protected:
    TokenUPD intToken;
    IdentifierUPD identifier;
    TokenUPD constantToken;
public:
    UnsignedIntTerm();
    void execute() override;
};
using UnsignedIntTermUP = std::unique_ptr<UnsignedIntTerm>;


#endif //FISH_UNSIGNEDINTTERM_H
