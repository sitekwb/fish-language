//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/MultiplyExpression.h>


MultiplyExpression::MultiplyExpression(bool unaryMinus, TermUP &&term)
        : unaryMinus(unaryMinus),
          term(move(term)) {

}
