//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/File.h>

using namespace std;


File::File(std::list<FunctionDefinitionUP> &&funcDefList,
           std::list<ClassDefinitionUP> &&classDefList,
           std::list<StatementUP> &&statementList)
        : funcDefList(move(funcDefList)),
          classDefList(move(classDefList)),
          statementList(move(statementList)) {

}

