//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/BlockInstruction.h>

using namespace std;

BlockInstruction::BlockInstruction(std::list<StatementUP> &&statementList)
    :statementList(move(statementList)){

}

