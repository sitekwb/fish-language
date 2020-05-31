//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
#include "Analizator/Interpreter/GlobalEnv.h"

bool GlobalEnv::isGlobalEnv() const{
    return true;
}

void GlobalEnv::setLocalSymbol(std::string name, const Symbol &symbol) {
    // TODO logic what with existing
    hashMap[name] = symbol;
}

Object & GlobalEnv::operator (std::string name) {
    if(hashMap.count(name)){
        return hashMap[name];
    }
    throw SymbolNotFoundException(name);
}
