//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_ENV_H
#define FISH_ENV_H


#include <string>
#include <map>
#include "Obj.h"

class Env;

using EnvUP = std::unique_ptr<Env>;

class Obj;

using EnvironmentHashMap = std::map<std::string, std::reference_wrapper<Obj>>;

class Env {
    EnvironmentHashMap hashMap;
    Env &parent;
    bool isGlobal = false;
public:
    Env(Env &parentEnv);

    Env();

    Env &operator=(Env &other);

    void setSymbol(std::string name, std::reference_wrapper<Obj> object);

    Obj &operator[](std::string name);

    void setGlobalSymbol(std::string name, std::reference_wrapper<Obj> object);

    void destroySymbol(std::string name);

};


#endif //FISH_ENV_H
