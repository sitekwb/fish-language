//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_COMMANDLINESOURCE_H
#define FISH_COMMANDLINESOURCE_H


#include <Src.h>
#include <sstream>

class CommandLineSource : public Src {
    std::stringstream buf;
    static const unsigned int MAX_LINE_LEN = 256;
    bool last;
    void printPrompt() const;
    void printDebug(TokenType const &tokenType, std::string const &value) override;
public:
    CommandLineSource();
    void serve();
    char peek() override;
    char get() override;
    std::string exchangeToken(TokenType tokenType, std::string &value) const override;
    ~CommandLineSource() override = default;
};


#endif //FISH_COMMANDLINESOURCE_H
