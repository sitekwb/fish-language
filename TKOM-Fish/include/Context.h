//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_CONTEXT_H
#define FISH_CONTEXT_H


class Context {
    unsigned int lineNumber, signNumber, signNumberInLine;

public:
    Context();

    void nextLineNumber();
    void nextSignNumber();

    unsigned int getLineNumber() const;

    unsigned int getSignNumber() const;

    unsigned int getSignNumberInLine() const;
};


#endif //FISH_CONTEXT_H
