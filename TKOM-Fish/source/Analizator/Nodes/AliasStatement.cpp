//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/AliasStatement.h>

//
//void AliasStatement::execute(Env &env) {
//    if(!constructed){
//        return;
//    }
//    env.setSymbol(name->getName(), *type);
//}

AliasStatement::AliasStatement(std::string &&aliasType, std::string &&type)
        : aliasType(move(aliasType)),
          type(move(type)) {

}
