//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_IDENTIFIER_H
#define FISH_IDENTIFIER_H


#include <Analizator/Tokens/Token.h>
#include <Analizator/Tokens/TokenDeleter.h>

class Identifier : public Token {
public:
    Identifier();

    Identifier(Token &token);
    friend class Test;
};

using IdentifierUP = std::unique_ptr<Identifier>;
using IdentifierUPD = std::unique_ptr<Identifier, TokenDeleter>;


#endif //FISH_IDENTIFIER_H
