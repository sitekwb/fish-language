//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/ImportStatement.h>

ImportStatement::ImportStatement(std::string &&libName,
                                 std::string &&libAlias)
        : libName(move(libName)),
          libAlias(move(libAlias)) {

}

//
//void ImportStatement::initialize(Env &env) {
//    lib = std::make_unique<Lib>(library->getValue());
//    env.setSymbol((library2) ? library2->getValue() : library->getValue(), *lib);
//}
//
//void ImportStatement::execute(Env &env) {
//    lib->execute(env);
//}