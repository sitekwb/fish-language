//
// Created by Wojtek on 15/04/2020.
//

#include "../../../include/Exceptions/LengthException.h"

LengthException::LengthException(LexerState lexerState) : state(lexerState), runtime_error("Too long text!"){

}
