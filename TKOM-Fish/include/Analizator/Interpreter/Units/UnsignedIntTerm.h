//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNSIGNEDINTTERM_H
#define FISH_UNSIGNEDINTTERM_H


#include <Analizator/Interpreter/Symbol.h>

class UnsignedIntTerm : public Symbol{
    using UnsignedIntTermUP = std::unique_ptr<UnsignedIntTerm>;
protected:

public:
    void execute() override;
};


#endif //FISH_UNSIGNEDINTTERM_H
