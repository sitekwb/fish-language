//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_OBJECTTYPE_H
#define FISH_OBJECTTYPE_H

enum class ObjectType {
    OT_STRING,
    OT_INT,
    OT_DOUBLE,
    OT_IDENTIFIER,
    OT_CONSTANT,
    OT_KEYWORD,
    OT_TOKEN,
    OT_AddExpression,
    OT_AddOperator,
    OT_AliasStatement,
    OT_AndExpression,
    OT_Argument,
    OT_ArgumentList,
    OT_ArithmeticExpression,
    OT_ArraySubscript,
    OT_AssignExpression,
    OT_AssignOperator,
    OT_AssignStatement,
    OT_BlockInstruction,
    OT_Bool,
    OT_ClassBody,
    OT_ClassBodyStatement,
    OT_ClassDefinition,
    OT_CompoundStatement,
    OT_ConditionalExpression,
    OT_ControlStatement,
    OT_Default,
    OT_DeleteStatement,
    OT_Expression,
    OT_ExpressionStatement,
    OT_File,
    OT_FilePart,
    OT_ForeachStatement,
    OT_ForiStatement,
    OT_ForStatement,
    OT_FunctionCall,
    OT_FunctionDefinition,
    OT_IfStatement,
    OT_ImportStatement,
    OT_MemberDefinition,
    OT_MultiplyExpression,
    OT_MultiplyOperator,
    OT_NewExpression,
    OT_NewStatement,
    OT_OrExpression,
    OT_Parameter,
    OT_ParameterList,
    OT_RelativeExpression,
    OT_RelativeOperator,
    OT_SimpleStatement,
    OT_Statement,
    OT_Term,
    OT_Type,
    OT_UnaryNot,
    OT_UnarySign,
    OT_UnsignedIntTerm,
    OT_WhileStatement,
    OT_Symbol,
    OT_Lib,
};

#endif //FISH_OBJECTTYPE_H
