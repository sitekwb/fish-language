//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Nodes/DeleteStatement.h"

using namespace std;

DeleteStatement::DeleteStatement(std::string &&idName)
        : idName(move(idName)) {

}
//
//void DeleteStatement::execute(Env &env) {
//    env.destroySymbol(identifier->getValue());
//}
