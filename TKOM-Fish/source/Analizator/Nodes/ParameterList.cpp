//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/ParameterList.h>
#include <list>

using namespace std;

ParameterList::ParameterList(std::list<ParameterUP> &&parameterList)
        : parameterList(move(parameterList)) {

}
//const std::string ParameterList::getNodeName() {
//    return "Parameter List";
//}