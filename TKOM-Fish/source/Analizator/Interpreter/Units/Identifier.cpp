//
// Created by Wojtek on 28/05/2020.
//

#include "Analizator/Interpreter/Identifier.h"

Identifier::Identifier() : Token(IDENTIFIER) {

}

Identifier::Identifier(Token &token) : Token(IDENTIFIER, token.getValue()){
    if(token.getType() != IDENTIFIER){
        throw std::exception();
    }
}
