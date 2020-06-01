//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_GLOBALENV_H
#define FISH_GLOBALENV_H

#include <string>
#include <map>

class Obj;

using EnvironmentHashMap = std::map<std::string, std::reference_wrapper<Obj>>;


class GlobalEnv {
protected:
    EnvironmentHashMap hashMap;
    virtual bool isGlobalEnv() const;
public:
    GlobalEnv &operator=(GlobalEnv &other);
    virtual void setSymbol(std::string name, std::reference_wrapper<Obj> object);
    virtual Obj & operator[](std::string name);
    friend class Env;
};


#endif //FISH_GLOBALENV_H
