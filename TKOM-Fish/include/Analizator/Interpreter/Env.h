//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_ENV_H
#define FISH_ENV_H


#include <map>
#include <string>
#include "Object.h"
#include "GlobalEnv.h"

class Env;
using EnvUP = std::unique_ptr<Env>;

class Env : public GlobalEnv{
    GlobalEnv &parentEnv;
    bool isGlobalEnv() const override;
public:
    Env(GlobalEnv &parentEnv);
    void setGlobalSymbol(std::string name, Object &object);
    void destroySymbol(std::string name);
    Object &operator[](std::string name) override;
};


#endif //FISH_ENV_H
