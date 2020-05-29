//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ParameterList.h"

using namespace std;

ParameterList::ParameterList() {
    if(buildSymbol<Parameter>(parameter)){
        TokenUPD comma;
        ParameterUP parameterUP;
        while(buildToken(",", comma) and buildSymbol<Parameter>(parameterUP)){
            repeatList.push_back({move(comma), move(parameterUP)});
        }
    }
}

void ParameterList::execute() {
    //TODO
}
