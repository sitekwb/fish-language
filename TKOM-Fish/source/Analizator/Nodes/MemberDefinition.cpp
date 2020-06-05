//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/MemberDefinition.h>
#include <list>

using namespace std;



MemberDefinition::MemberDefinition(MBP memberDefinitionPublic, bool mutBool, bool staticBool,
                                   string &&typeNameOpt,
                                   string &&idName)
                                   : memberDefinitionPublic(memberDefinitionPublic),
                                   mutBool(mutBool),
                                   staticBool(staticBool),
                                   typeNameOpt(move(typeNameOpt)),
                                   idName(move(idName)) {

}
