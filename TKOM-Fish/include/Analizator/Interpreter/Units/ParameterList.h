//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETERLIST_H
#define FISH_PARAMETERLIST_H


#include <Analizator/Interpreter/Symbol.h>

class ParameterList : public Symbol{
    using ParameterListUP = std::unique_ptr<ParameterList>;
protected:

public:
    void execute() override;
};


#endif //FISH_PARAMETERLIST_H
