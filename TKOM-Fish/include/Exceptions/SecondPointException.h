//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_SECONDPOINTEXCEPTION_H
#define FISH_SECONDPOINTEXCEPTION_H


#include <exception>
#include <stdexcept>

class SecondPointException : public std::runtime_error {
public:
    SecondPointException();
};


#endif //FISH_SECONDPOINTEXCEPTION_H
