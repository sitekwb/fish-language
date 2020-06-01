//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/NotImplementedException.h>
#include "Analizator/Interpreter/Object.h"


Object &Object::getObject() {
    throw NotImplementedException();
}

void Object::execute(Env &env) {
    throw NotImplementedException();
}
