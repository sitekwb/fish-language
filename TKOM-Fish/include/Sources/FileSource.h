//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_FILESOURCE_H
#define FISH_FILESOURCE_H


#include <Src.h>
#include <fstream>

class FileSource : public Src {
    std::unique_ptr<std::ifstream> buf;
public:
    explicit FileSource(std::unique_ptr<std::ifstream> buf);
    char peek() override;
    char get() override;
    void printDebug(TokenType const &tokenType, std::string const &value) override;
    std::string exchangeToken(TokenType tokenType, std::string &value) const  override;
    virtual ~FileSource(){}
};


#endif //FISH_FILESOURCE_H
