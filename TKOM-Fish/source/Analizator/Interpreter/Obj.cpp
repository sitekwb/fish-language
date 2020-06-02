//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/NotImplementedException.h>
#include <Analizator/Interpreter/BreakException.h>
#include "Analizator/Interpreter/Obj.h"


Obj &Obj::evaluateObject() {
    evaluateList();
    if(objectList.empty()){
        throw BreakException();
    }
    return objectList.front();
}


int Obj::getInt() const {
    if(objectList.empty()){
        return 0;
    }
    return objectList.front().get().getInt();
}

double Obj::getDouble() const {
    if(objectList.empty()){
        return 0;
    }
    return objectList.front().get().getDouble();
}

std::string Obj::getString() const {
    if(objectList.empty()){
        return "";
    }
    return objectList.front().get().getString();
}

bool Obj::getBool() const {
    if(objectList.empty()){
        return true;
    }
    return objectList.front().get().getBool();
}

bool Obj::isFinal() const {
    return false;
}

ObjectList &Obj::evaluateList() {
    for(auto &e:objectList) {
        while (not e.get().isFinal()) {
            try {
                e = e.get().evaluateObject();
            }
            catch(BreakException &e){
                break;
            }
        }
    }
    return objectList;
}

Obj &Obj::getObject() {
    if(objectList.empty()){
        return *this;
    }
    return objectList.front();
}

Obj &Obj::operator[](int n) {
    auto it = objectList.begin();
    for(int i=0; i<n; ++i) {
        ++it;
    }
    return *it;
}
//
//std::string Obj::getName() const {
//    if(objectList.empty()){
//        return "";
//    }
//    return objectList.front().get().getName();
//}
