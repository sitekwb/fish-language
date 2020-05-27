//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_TERM_H
#define FISH_TERM_H


#include <Analizator/Interpreter/Symbol.h>

class Term : public Symbol{
    using TermUP = std::unique_ptr<Term>;
protected:

public:
    void execute() override;
};

#endif //FISH_TERM_H
