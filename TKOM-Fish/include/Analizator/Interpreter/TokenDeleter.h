//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_TOKENDELETER_H
#define FISH_TOKENDELETER_H

#include <Analizator/Lexer/Token.h>


class TokenDeleter{
    static bool shouldTokenBeSaved;
public:
    TokenDeleter();
    void operator()(Token *token);
    static void setTokenSaving(bool value);
    //friend class Symbol;
};

#endif //FISH_TOKENDELETER_H
