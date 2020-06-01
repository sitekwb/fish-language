//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/NotImplementedException.h>
#include "Analizator/Interpreter/Obj.h"


Obj &Obj::getObject() {
    throw NotImplementedException();
}

void Obj::execute(Env &env) {
    throw NotImplementedException();
}

std::string Obj::getName() const {
    throw NotImplementedException();
}

Obj &Obj::operator[](int i) {
    throw NotImplementedException();
}

int Obj::getInt() const {
    throw NotImplementedException();
}

double Obj::getDouble() const {
    throw NotImplementedException();
}

std::string Obj::getString() const {
    throw NotImplementedException();
}

bool Obj::getBool() const {
    throw NotImplementedException();
}
