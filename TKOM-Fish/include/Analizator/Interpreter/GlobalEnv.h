//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_GLOBALENV_H
#define FISH_GLOBALENV_H

#include "Object.h"
#include <string>

class Object;

using EnvironmentHashMap = std::map<std::string, Object&>;


class GlobalEnv {
protected:
    EnvironmentHashMap hashMap;
    virtual bool isGlobalEnv() const;
public:
    GlobalEnv &operator=(GlobalEnv &other);
    virtual void setSymbol(std::string name, Object &object);
    virtual Object & operator[](std::string name);
    friend class Env;
};


#endif //FISH_GLOBALENV_H
