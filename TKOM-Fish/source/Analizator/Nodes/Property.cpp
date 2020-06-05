//
// Created by Wojtek on 04/06/2020.
//

#include "Analizator/Nodes/Property.h"

using namespace std;

Property::Property(std::list<std::string> &&idNameList)
        : idNameList(move(idNameList)) {

}
