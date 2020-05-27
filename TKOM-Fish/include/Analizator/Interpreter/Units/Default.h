//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_DEFAULT_H
#define FISH_DEFAULT_H


#include <Analizator/Interpreter/Symbol.h>

class Default : public Symbol{
    using DefaultUP = std::unique_ptr<Default>;
protected:

public:
    void execute() override;
};

#endif //FISH_DEFAULT_H
