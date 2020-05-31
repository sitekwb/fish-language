//
// Created by Wojtek on 28/05/2020.
//

#include "Analizator/Tokens/Identifier.h"

Identifier::Identifier() : Token(IDENTIFIER) {

}

Identifier::Identifier(Token &token) : Token(IDENTIFIER, token.getValue(), token.getContext()){
    if(token.getType() != IDENTIFIER){
        throw std::exception();
    }
}
