//
// Created by Wojtek on 04/06/2020.
//

#ifndef FISH_PROPERTY_H
#define FISH_PROPERTY_H


#include <memory>
#include <list>
#include <string>

class Property {
    std::list<std::string> idNameList;
public:
    Property(std::list<std::string> &&idNameList);
};

using PropertyUP = std::unique_ptr<Property>;


#endif //FISH_PROPERTY_H
