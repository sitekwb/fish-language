//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDOPERATOR_H
#define FISH_ADDOPERATOR_H

#include <memory>

class AddOperator {
protected:
    bool isPlus;
public:
    AddOperator(bool isPlus);
};
using AddOperatorUP = std::unique_ptr<AddOperator>;


#endif //FISH_ADDOPERATOR_H
