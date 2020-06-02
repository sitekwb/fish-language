//
// Created by Wojtek on 31/05/2020.
//

#include <iostream>
#include <Analizator/Tokens/Token.h>
#include "Analizator/Interpreter/Lib.h"

Lib::Lib(std::string name_) :name(std::move(name_)){
}

ObjectType Lib::getObjectType() const {
    return ObjectType::OT_Lib;
}

bool Lib::isFinal() const {
    return true;
}


void Lib::execute(Env &env) {
    if(name == "print"){
        std::cout << static_cast<Token &>(env["__0__"]).getValue();
        std::cout.flush();
    }
}
