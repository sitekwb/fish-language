//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/UnarySign.h"

UnarySign::UnarySign() {
    constructed = buildToken("+", token) or buildToken("-", token);
}

void UnarySign::execute() {

}
