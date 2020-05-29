//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_IDENTIFIER_H
#define FISH_IDENTIFIER_H


#include <Analizator/Lexer/Token.h>
#include <Analizator/Interpreter/TokenDeleter.h>

class Identifier : public Token{
public:
    Identifier();
    Identifier(Token &token);
};

using IdentifierUP = std::unique_ptr<Identifier>;
using IdentifierUPD = std::unique_ptr<Identifier, TokenDeleter>;


#endif //FISH_IDENTIFIER_H
