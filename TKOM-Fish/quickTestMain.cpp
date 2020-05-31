
#include <Controller.h>
#include <iostream>
#include <Sources/CommandLineSource.h>
#include <ProgramOptions.h>
#include <Sources/FileSource.h>
#include <Analizator/EndOfFileException.h>

using namespace std;

int main(int argc, char *argv[]) {
    auto source = FileSource(make_unique<ifstream>("../examples/example2"));
    Symbol::setLexer(make_unique<Lexer>(source));

    return 0;
}
