//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FILE_H
#define FISH_FILE_H


#include <list>
#include <Analizator/Lexer/Lexer.h>
#include "FunctionDefinition.h"
#include "ClassDefinition.h"
#include "Statement.h"

class File {
    std::list<FunctionDefinitionUP> funcDefList;
    std::list<ClassDefinitionUP> classDefList;
    std::list<StatementUP> statementList;
public:
    File(std::list<FunctionDefinitionUP> &&funcDefList, std::list<ClassDefinitionUP> &&classDefList, std::list<StatementUP> &&statementList);
};
using FileUP = std::unique_ptr<File>;


#endif //FISH_FILE_H
