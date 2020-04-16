//
// Created by Wojtek on 15/04/2020.
//
#include <Exceptions/UnknownSignException.h>



UnknownSignException::UnknownSignException(char c) : value(c), runtime_error("UnknownSignException: sign"+c){

}
