//
// Created by Wojtek on 03/06/2020.
//

#ifndef FISH_GLOBALSCOPE_H
#define FISH_GLOBALSCOPE_H


#include <map>
#include <list>
#include "Object.h"
#include "Lib.h"
#include "FunctionScope.h"

using EnvVariant = std::variant<std::reference_wrapper<Object>, std::reference_wrapper<FunctionDefinition>, std::reference_wrapper<ClassDefinition>>;

class GlobalScope : public FunctionScope {
protected:
    std::list<FunctionScope>embeddedScopes;
public:
    EnvVariant get(const std::string &name)const;
};
#endif //FISH_GLOBALSCOPE_H
