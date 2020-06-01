//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_UNSIGNEDINTTERM_H
#define FISH_UNSIGNEDINTTERM_H

#include <Analizator/Symbols/Term.h>
#include <Analizator/Symbol.h>

class Term;
using TermUP = std::unique_ptr<Term>;

class UnsignedIntTerm : public Symbol{
protected:
    TermUP term;
public:
    UnsignedIntTerm();
    void execute(Env &env) override;
    int getInt() const override;
};
using UnsignedIntTermUP = std::unique_ptr<UnsignedIntTerm>;


#endif //FISH_UNSIGNEDINTTERM_H
