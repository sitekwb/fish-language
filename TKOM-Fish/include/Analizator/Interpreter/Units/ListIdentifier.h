//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_LISTIDENTIFIER_H
#define FISH_LISTIDENTIFIER_H


#include <Analizator/Interpreter/Symbol.h>

class ListIdentifier: public Symbol{
    using ListIdentifierUP = std::unique_ptr<ListIdentifier>;
protected:

public:
    void execute() override;
};

#endif //FISH_LISTIDENTIFIER_H
