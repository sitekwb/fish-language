#include <Analizator/Interpreter/Units/FilePart.h>
#include "Analizator/Interpreter/Interpreter.h"

void Interpreter::interprete(Parser &parser) {
    parser.cleanTree();
    auto &symbol = parser.getTree();
    auto filePart = FilePart(symbol);
    filePart.execute();
}
