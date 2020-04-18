//
// Created by Wojtek on 17/04/2020.
//

#include "Sources/FileSource.h"

char FileSource::peek() {
    return buf->peek();
}

char FileSource::get() {
    return buf->get();
}

void FileSource::printDebug(TokenType const &tokenType, std::string const &value) {
    // pass
}

FileSource::FileSource(std::unique_ptr<std::ifstream> buf_) : buf(std::move(buf_)) {

}

std::string FileSource::exchangeToken(TokenType tokenType, std::string &value) const {
    return std::move(value);
}
