//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_GLOBALENV_H
#define FISH_GLOBALENV_H

#include <string>
#include <Analizator/Symbol.h>

class Symbol;

using EnvironmentHashMap = std::map<std::string, Object&>;


class GlobalEnv {
protected:
    EnvironmentHashMap hashMap;
    virtual bool isGlobalEnv() const;
public:
    virtual void setSymbol(std::string name, Object &symbol);
    virtual Object & operator[](std::string name);
    friend class Env;
};


#endif //FISH_GLOBALENV_H
