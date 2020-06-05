//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_DELETESTATEMENT_H
#define FISH_DELETESTATEMENT_H

#include "Statement.h"
#include <string>

class DeleteStatement: public Statement{
protected:
    std::string idName;
public:
    DeleteStatement(std::string &&idName);
};

using DeleteStatementUP = std::unique_ptr<DeleteStatement>;
#endif //FISH_DELETESTATEMENT_H
