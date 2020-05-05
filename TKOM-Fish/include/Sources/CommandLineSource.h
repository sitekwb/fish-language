//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_COMMANDLINESOURCE_H
#define FISH_COMMANDLINESOURCE_H


#include <Source.h>
#include <sstream>

class CommandLineSource : public Source {
    const char FINISH_SIGN = '$';
    std::stringstream buf;
    bool initialisation, last;
    void printPrompt() const;
    void printStringPrompt() const;
    static char exchangeEOF(char c) ;
public:
    CommandLineSource();
    void serve(bool isString = false);
    char peek() override;
    char get() override;
    char getStringSign() override;
    char peekStringSign() override;
    ~CommandLineSource() override = default;
};


#endif //FISH_COMMANDLINESOURCE_H
