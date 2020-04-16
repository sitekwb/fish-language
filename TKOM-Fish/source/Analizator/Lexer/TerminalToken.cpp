//
// Created by Wojtek on 15/04/2020.
//

#include "Analizator/Lexer/TerminalToken.h"
#include <ostream>

void TerminalToken::print(std::ostream &os) const{
    os << static_cast<char>(static_cast<std::underlying_type<TerminalEnum>::type>(this->terminalEnum)) << "\t\t[TERMINAL]";
}

TerminalToken::TerminalToken(TerminalEnum terminal) : terminalEnum(std::move(terminal)){

}