//
// Created by Wojtek on 03/06/2020.
//

#include "Analizator/Interpreter/GlobalScope.h"


EnvVariant GlobalScope::get(const std::string &name)const{
    auto &classDefinition = classMap.at(name);
    return EnvVariant(*classDefinition);
    //TODO
}
