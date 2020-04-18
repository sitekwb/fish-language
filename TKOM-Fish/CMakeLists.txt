cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/*)

find_package(Boost COMPONENTS system filesystem REQUIRED)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

set(S_EXCEPTIONS source/Analizator/Exceptions/UnknownSignException.cpp source/Analizator/Exceptions/SecondPointException.cpp)
set(S_LEXER source/Analizator/Lexer/Lexer.cpp source/Analizator/Lexer/Token.cpp)
set(SOURCES source/Context.cpp source/Controller.cpp source/Analizator/Parser/LanguageParser.cpp source/Src.cpp source/Sources/CommandLineSource.cpp source/Sources/FileSource.cpp)
message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${S_EXCEPTIONS} ${S_LEXER} ${SOURCES})

target_link_libraries(Fish
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )

