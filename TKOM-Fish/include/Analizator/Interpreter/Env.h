//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_ENV_H
#define FISH_ENV_H


#include <string>
#include "GlobalEnv.h"
#include "Obj.h"

class Env;
using EnvUP = std::unique_ptr<Env>;

class GlobalEnv;
using GlobalEnvUP = std::unique_ptr<GlobalEnv>;

class Env : public GlobalEnv{
    GlobalEnv &parentEnv;
    bool isGlobalEnv() const override;
public:
    Env(GlobalEnv &parentEnv);
    void setGlobalSymbol(std::string name, std::reference_wrapper<Obj> object);
    void destroySymbol(std::string name);
    Obj &operator[](std::string name) override;
};


#endif //FISH_ENV_H
