//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/Parameter.h>

Parameter::Parameter(std::string &&type, std::string &&name, TermUP &&defaultTerm)
        : name(name), type(type), defaultTermOpt(move(defaultTerm)) {
}

const std::string Parameter::getNodeName() {
    return "Parameter";
}


