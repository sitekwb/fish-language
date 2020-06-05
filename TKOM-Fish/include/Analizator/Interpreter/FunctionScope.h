//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_FUNCTIONSCOPE_H
#define FISH_FUNCTIONSCOPE_H

#include <Analizator/Nodes/FunctionDefinition.h>
#include <string>
#include <map>
#include <Analizator/Nodes/ClassDefinition.h>
#include "Lib.h"
#include "Object.h"

class FunctionScope {
protected:
    //std::map<std::string, FunctionDefinitionUP> functionMap;
    //std::map<std::string, ClassDefinitionUP> classMap;
    std::map<std::string, ObjectUP> objectMap;
    std::map<std::string, LibUP> libMap;
public:


//    FunctionScope &operator=(FunctionScope &other);
//
//    void setFunctionDefinition(FunctionDefinitionUP &functionDefinition);
//
//
//    virtual Object &operator[](std::string name);
//
//    void setGlobalSymbol(std::string name, std::reference_wrapper<Object> object);
//
//    void destroySymbol(std::string name);

};


#endif //FISH_FUNCTIONSCOPE_H
