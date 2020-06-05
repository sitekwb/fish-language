//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_SOURCE_H
#define FISH_SOURCE_H

#include <memory>

class Source {

public:
    virtual char peek() = 0;
    virtual char get() = 0;
    virtual char getStringSign() = 0;
    virtual char peekStringSign() = 0;
    virtual ~Source() = default;
    virtual bool isFileSource() const = 0;
};

typedef std::unique_ptr<Source> SourceUP;

#endif //FISH_SOURCE_H
