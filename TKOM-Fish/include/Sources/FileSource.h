//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_FILESOURCE_H
#define FISH_FILESOURCE_H


#include <Source.h>
#include <fstream>

class FileSource : public Source {
    std::unique_ptr<std::ifstream> buf;
public:
    explicit FileSource(std::unique_ptr<std::ifstream> buf);
    char peek() override;
    char get() override;
    char getStringSign() override;
    char peekStringSign() override;
    virtual ~FileSource(){}
};


#endif //FISH_FILESOURCE_H
