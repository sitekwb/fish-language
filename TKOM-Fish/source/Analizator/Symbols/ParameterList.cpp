//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ParameterList.h"

using namespace std;

ParameterList::ParameterList() {
    if(buildSymbol<Parameter>(parameter)){
        TokenUPD comma;
        ParameterUP parameterUP;
        while(buildToken(",", comma) and buildSymbol<Parameter>(parameterUP)){
            repeatList.push_back({move(comma), move(parameterUP)});
        }
        constructed = true;
    }
}

void ParameterList::execute(Env &env) {
    parameter->execute(env);
    parameterList.push_back(*parameter);
    for(auto &pair: repeatList){
        pair.second->execute(env);
        parameterList.push_back(*pair.second);
    }
}
