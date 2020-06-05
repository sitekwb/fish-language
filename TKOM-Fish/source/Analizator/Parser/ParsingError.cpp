//
// Created by Wojtek on 03/06/2020.
//

#include "Analizator/Parser/ParsingError.h"

ParsingError::ParsingError(const Token &token, const std::string &shouldBe, const std::string &symbolName)
        : std::runtime_error(token.getErrorMessage() +
                             "Expected: " + shouldBe +
                             ". In: " + symbolName) {

}
