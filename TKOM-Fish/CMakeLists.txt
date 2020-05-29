cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/* include/*/*/*/*/*)

find_package(Boost 1.45.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

set(S_EXCEPTIONS source/Analizator/Exceptions/SecondPointException.cpp source/Analizator/Exceptions/UnknownSignException.cpp)
set(S_LEXER source/Analizator/Lexer/Lexer.cpp source/Analizator/Lexer/Token.cpp)
set(S_PARSER source/Analizator/Parser/Parser.cpp source/Analizator/Parser/Repeat.cpp source/Analizator/Parser/SymbolOld.cpp source/Analizator/Parser/SymbolOld.cpp source/Analizator/Parser/SymbolTypeOld.cpp source/Analizator/Interpreter/EndOfFileException.cpp include/Analizator/Interpreter/EndOfFileException.h)
set(S_INTERPRETER source/Analizator/Interpreter/Interpreter.cpp source/Analizator/Interpreter/Units/FilePart.cpp source/Analizator/Interpreter/Units/Statement.cpp source/Analizator/Interpreter/Units/Bool.cpp source/Analizator/Interpreter/Units/File.cpp source/Analizator/Interpreter/TokenDeleter.cpp)
set(S_UNITS source/Analizator/Interpreter/Units/FunctionDefinition.cpp source/Analizator/Interpreter/Units/ClassDefinition.cpp source/Analizator/Interpreter/Units/Type.cpp source/Analizator/Interpreter/Units/SimpleStatement.cpp source/Analizator/Interpreter/Units/ExpressionStatement.cpp source/Analizator/Interpreter/Units/DeleteStatement.cpp source/Analizator/Interpreter/Units/ImportStatement.cpp source/Analizator/Interpreter/Units/NewStatement.cpp source/Analizator/Interpreter/Units/AssignStatement.cpp source/Analizator/Interpreter/Units/AliasStatement.cpp source/Analizator/Interpreter/Units/Expression.cpp source/Analizator/Interpreter/Units/NewExpression.cpp source/Analizator/Interpreter/Units/AssignExpression.cpp source/Analizator/Interpreter/Units/ConditionalExpression.cpp source/Analizator/Interpreter/Units/AndExpression.cpp source/Analizator/Interpreter/Units/OrExpression.cpp source/Analizator/Interpreter/Units/RelativeExpression.cpp source/Analizator/Interpreter/Units/ArithmeticExpression.cpp source/Analizator/Interpreter/Units/AddExpression.cpp source/Analizator/Interpreter/Units/MultiplyExpression.cpp source/Analizator/Interpreter/Units/Term.cpp source/Analizator/Interpreter/Units/FunctionCall.cpp source/Analizator/Interpreter/Units/ArgumentList.cpp source/Analizator/Interpreter/Units/Argument.cpp source/Analizator/Interpreter/Units/AssignOperator.cpp source/Analizator/Interpreter/Units/RelativeOperator.cpp source/Analizator/Interpreter/Units/AddOperator.cpp source/Analizator/Interpreter/Units/MultiplyOperator.cpp source/Analizator/Interpreter/Units/UnarySign.cpp source/Analizator/Interpreter/Units/UnaryNot.cpp source/Analizator/Interpreter/Units/ArraySubscript.cpp source/Analizator/Interpreter/Units/UnsignedIntTerm.cpp source/Analizator/Interpreter/Units/CompoundStatement.cpp source/Analizator/Interpreter/Units/BlockInstruction.cpp source/Analizator/Interpreter/Units/IfStatement.cpp source/Analizator/Interpreter/Units/WhileStatement.cpp source/Analizator/Interpreter/Units/ForStatement.cpp source/Analizator/Interpreter/Units/ForiStatement.cpp source/Analizator/Interpreter/Units/ForeachStatement.cpp source/Analizator/Interpreter/Units/ParameterList.cpp source/Analizator/Interpreter/Units/Parameter.cpp source/Analizator/Interpreter/Units/Default.cpp source/Analizator/Interpreter/Units/ClassBody.cpp source/Analizator/Interpreter/Units/ClassBodyStatement.cpp source/Analizator/Interpreter/Units/MemberDefinition.cpp source/Analizator/Interpreter/Units/ListIdentifier.cpp source/Analizator/Interpreter/Symbol.cpp source/Analizator/Interpreter/Units/ControlStatement.cpp source/Analizator/Interpreter/Units/Identifier.cpp)
set(S_SOURCES source/Sources/CommandLineSource.cpp source/Sources/FileSource.cpp source/Controller.cpp source/Controller.cpp source/ProgramOptions.cpp source/Source.cpp source/Context.cpp)
message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${S_EXCEPTIONS} ${S_LEXER} ${S_PARSER} ${S_UNITS} ${S_INTERPRETER} ${S_SOURCES} source/Tests/test.cpp)

if(Boost_FOUND)
    target_link_libraries(Fish ${Boost_LIBRARIES})
endif()