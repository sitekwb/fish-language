//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_DEFAULT_H
#define FISH_DEFAULT_H


#include <Analizator/Symbol.h>
#include "Term.h"

class Term;
using TermUP = std::unique_ptr<Term>;

class Default : public Symbol{
protected:
    TermUP term;
public:
    Default();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;

};
using DefaultUP = std::unique_ptr<Default>;

#endif //FISH_DEFAULT_H
