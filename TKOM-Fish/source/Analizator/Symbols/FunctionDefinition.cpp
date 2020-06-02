//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/FunctionDefinition.h"

using namespace std;

FunctionDefinition::FunctionDefinition() :blockInstructionCopy(blockInstruction) {
    // "def"
    if (not buildToken("def", def)) {
        return;
    }

    // [Type], identifier
    IdentifierUPD id;
    if (not buildToken(id)) {
        return;
    }

    if (buildToken(identifier)) {
        id.reset();
        buildSymbol<Type>(typeOptional);
    } else {
        id.reset();
        buildToken(identifier);
    }

    // '(', ParameterList, ')', BlockInstruction
    constructed = buildToken("(", bracketOpen)
                  and buildSymbol<ParameterList>(parameterList)
                  and buildToken(")", bracketClose)
                  and buildSymbol<BlockInstruction>(blockInstruction);
}

std::string FunctionDefinition::getName() {
    return identifier->getValue();
}

void FunctionDefinition::execute(Env &env) {
    blockInstructionCopy->execute(env);
}

int FunctionDefinition::getInt() const {
    return parameterList->getInt();
}

ObjectType FunctionDefinition::getObjectType() const {
    return ObjectType::OT_FunctionDefinition;
}

void FunctionDefinition::initialize(Env &env) {
    parameterList->execute(env);
    objectList.push_back(*parameterList);
    evaluateList();
}

FunctionDefinition::FunctionDefinition(FunctionDefinition &f)
        : blockInstructionCopy(f.blockInstruction){

}

