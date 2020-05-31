//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNSIGNEDINTTERM_H
#define FISH_UNSIGNEDINTTERM_H


#include <Analizator/Symbol.h>
#include <Analizator/Symbols/Term.h>

class Term;
using TermUP = std::unique_ptr<Term>;

class UnsignedIntTerm : public Symbol{
protected:
    TermUP term;
public:
    UnsignedIntTerm();
    void execute() override;
};
using UnsignedIntTermUP = std::unique_ptr<UnsignedIntTerm>;


#endif //FISH_UNSIGNEDINTTERM_H
