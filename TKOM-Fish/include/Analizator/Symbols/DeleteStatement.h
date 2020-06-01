//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_DELETESTATEMENT_H
#define FISH_DELETESTATEMENT_H


#include <Analizator/Symbol.h>

class DeleteStatement: public Symbol{
protected:
    TokenUPD deleteToken;
    IdentifierUPD identifier;
    //INTERP done
public:
    DeleteStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
};

using DeleteStatementUP = std::unique_ptr<DeleteStatement>;
#endif //FISH_DELETESTATEMENT_H
