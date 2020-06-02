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

Identifier::Identifier(std::string value) : Token(IDENTIFIER, move(value)){

}


ObjectType Identifier::getObjectType() const {
    return ObjectType::OT_IDENTIFIER;
}

bool Identifier::isFinal() const {
    return true;
}
