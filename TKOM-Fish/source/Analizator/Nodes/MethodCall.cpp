//
// Created by Wojtek on 04/06/2020.
//

#include "Analizator/Nodes/MethodCall.h"

using namespace std;

MethodCall::MethodCall(std::list<std::string> &&idNameList,
        FunctionCallUP &&functionCall)
: idNameList(move(idNameList)),
functionCall(move(functionCall)){

}
