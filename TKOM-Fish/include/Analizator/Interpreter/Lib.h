//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_LIB_H
#define FISH_LIB_H

#include <string>

class Lib {
    std::string name;

//    void initStd();
public:
    Lib(std::string &&name);
//    void execute(Env &env);
};
using LibUP = std::unique_ptr<Lib>;


#endif //FISH_LIB_H
