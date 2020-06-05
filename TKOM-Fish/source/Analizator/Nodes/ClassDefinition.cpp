//
// Created by Wojtek on 26/05/2020.
//

#include <list>
#include <Analizator/Nodes/ClassDefinition.h>
//
//void ClassDefinition::executeConstructor(FunctionScope &env, ArgumentListUP &argumentList) {
//    //TODO check
//    if (not argumentList) {
//        argumentList = std::make_unique<ArgumentList>(0);
//    }
//    int constructorSize = argumentList->getInt();
//    int i = 0;
//    bool found = true;
//    while (found) {
//        try {
//            std::string name = "__" + std::to_string(i) + getName();
//            auto &constructor = static_cast<FunctionDefinition &>(symbols[name]);
//            if (constructor.getInt() == constructorSize) {
//                FunctionCall constructorCall(name, *argumentList);
//                FunctionScope constrEnv(symbols);
//                constructorCall.execute(constrEnv);
//                break;
//            }
//        }
//        catch (SymbolNotFoundException &e) {
//            found = false;
//        }
//    }
//}

ClassDefinition::ClassDefinition(std::string &&typeName,
                                 std::list<ClassStatementUP> &&classStatementList)
        : typeName(move(typeName)),
          classStatementList(move(classStatementList)) {}
