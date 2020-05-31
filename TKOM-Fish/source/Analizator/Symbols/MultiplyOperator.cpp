//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/MultiplyOperator.h"

MultiplyOperator::MultiplyOperator() {
    if(buildToken("*", operatorToken)){
        value = '*';
        constructed = true;
    }
    else if(buildToken("/", operatorToken)){
        value = '/';
        constructed = true;
    }
    else if(buildToken("%", operatorToken)){
        value = '%';
        constructed = true;
    }

}

void MultiplyOperator::execute() {
//nothing
}

char MultiplyOperator::getChar() {
    return value;
}
