//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_CONTEXT_H
#define FISH_CONTEXT_H


class Context {
    unsigned line, sign, signInLine;

public:
    Context();

    void nextLine();
    void nextSign();

    unsigned int getLine() const;
    unsigned int getSign() const;
    unsigned int getSignInLine() const;
};


#endif //FISH_CONTEXT_H
