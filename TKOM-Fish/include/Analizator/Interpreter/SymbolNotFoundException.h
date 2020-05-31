//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_SYMBOLNOTFOUNDEXCEPTION_H
#define FISH_SYMBOLNOTFOUNDEXCEPTION_H


#include <string>

class SymbolNotFoundException {
    std::string name;
public:
    SymbolNotFoundException(std::string name);
};


#endif //FISH_SYMBOLNOTFOUNDEXCEPTION_H
