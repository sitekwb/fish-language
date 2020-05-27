//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETER_H
#define FISH_PARAMETER_H


#include <Analizator/Interpreter/Symbol.h>

class Parameter : public Symbol{
    using ParameterUP = std::unique_ptr<Parameter>;
protected:

public:
    void execute() override;
};

#endif //FISH_PARAMETER_H
