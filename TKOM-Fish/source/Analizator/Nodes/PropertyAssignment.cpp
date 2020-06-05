//
// Created by Wojtek on 04/06/2020.
//

#include "Analizator/Nodes/PropertyAssignment.h"

using namespace std;

PropertyAssignment::PropertyAssignment(std::list<std::string> &&idNameList,
                                       StatementUP &&assignStatement)
        : idNameList(move(idNameList)),
          assignStatement(move(assignStatement)) {

}
