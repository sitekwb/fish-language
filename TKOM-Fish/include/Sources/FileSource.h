//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_FILESOURCE_H
#define FISH_FILESOURCE_H


#include <Sources/Source.h>
#include <fstream>

class FileSource : public Source {
    std::unique_ptr<std::istream> buf;
public:
    explicit FileSource(std::unique_ptr<std::istream> buf);
    char peek() override;
    char get() override;
    char getStringSign() override;
    char peekStringSign() override;
    bool isFileSource() const override;
    virtual ~FileSource(){}
};


#endif //FISH_FILESOURCE_H
