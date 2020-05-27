//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARRAYSUBSCRIPT_H
#define FISH_ARRAYSUBSCRIPT_H


#include <Analizator/Interpreter/Symbol.h>

class ArraySubscript : public Symbol{
    using ArraySubscriptUP = std::unique_ptr<ArraySubscript>;
protected:

public:
    void execute() override;
};


#endif //FISH_ARRAYSUBSCRIPT_H
