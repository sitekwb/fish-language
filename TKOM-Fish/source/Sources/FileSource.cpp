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
