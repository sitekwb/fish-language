//
// Created by Wojtek on 17/04/2020.
//

#include "Sources/FileSource.h"

char FileSource::peek() {
    char c = buf->peek();
    if(not isEof and c == EOF){
        isEof = true;
        return ';';
    }
    return buf->peek();
}

char FileSource::get() {
    char c = peek();
    buf->get();
    return c;
}

FileSource::FileSource(std::unique_ptr<std::istream> buf_) : buf(std::move(buf_)) {

}

char FileSource::getStringSign() {
    return get();
}

char FileSource::peekStringSign() {
    return peek();
}

bool FileSource::isFileSource() const {
    return true;
}
