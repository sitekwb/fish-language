cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/*)

find_package(Boost COMPONENTS system filesystem REQUIRED)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

file(GLOB SOURCES "source/*.cpp source/*/*.cpp source/*/*/*.cpp source/*/*/*/*.cpp")
set(S_EXCEPTIONS source/Analizator/Exceptions/LengthException.cpp source/Analizator/Exceptions/SecondPointException.cpp)
set(PATH_NTT source/Analizator/Lexer/NonTerminalTokens/)
set(S_NONTERMINALTOKENS ${PATH_NTT}/Constant.cpp ${PATH_NTT}/ConstantValue.cpp ${PATH_NTT}/Dbl.cpp ${PATH_NTT}/Int.cpp ${PATH_NTT}/LowerVar.cpp ${PATH_NTT}/Str.cpp ${PATH_NTT}/Type.cpp ${PATH_NTT}/Variable.cpp)
set(S_LEXER source/Analizator/Lexer/Lexer.cpp source/Analizator/Lexer/Token.cpp source/Analizator/Lexer/TerminalToken.cpp)
set(S_CONTEXT source/Context.cpp source/Analizator/Exceptions/UnknownSignException.cpp)
message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${S_EXCEPTIONS} ${S_NONTERMINALTOKENS} ${S_LEXER} ${S_CONTEXT} source/Controller.cpp include/Controller.h source/Analizator/Parser/Parser.cpp)

target_link_libraries(Fish
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )

