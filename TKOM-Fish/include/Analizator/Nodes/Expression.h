//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSION_H
#define FISH_EXPRESSION_H

#include <list>
#include <variant>
#include "Statement.h"

class Expression : public Statement{
};
using ExpressionUP = std::unique_ptr<Expression>;

#endif //FISH_EXPRESSION_H
