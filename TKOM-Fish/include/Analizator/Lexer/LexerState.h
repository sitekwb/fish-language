//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_LEXERSTATE_H
#define FISH_LEXERSTATE_H


enum LexerState {
    S_STOP,
    S_STR_DBL_QUOTE,
    S_STR_SGL_QUOTE,
    S_INT,
    S_DBL,
    S_VARIABLE,
    S_LOWER_VAR,
    S_TYPE,
    S_CONSTANT,
    S_ZERO,
    S_EOF,
};


#endif //FISH_LEXERSTATE_H
