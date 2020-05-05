cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/*)

find_package(Boost 1.45.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

set(S_EXCEPTIONS source/Analizator/Exceptions/UnknownSignException.cpp source/Analizator/Exceptions/SecondPointException.cpp)
set(S_LEXER source/Analizator/Lexer/Lexer.cpp source/Analizator/Lexer/Token.cpp)
set(SOURCES source/Context.cpp source/Controller.cpp source/Analizator/Parser/Parser.cpp source/Source.cpp source/Sources/CommandLineSource.cpp source/Sources/FileSource.cpp source/ProgramOptions.cpp)
message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${S_EXCEPTIONS} ${S_LEXER} ${SOURCES})

if(Boost_FOUND)
    target_link_libraries(Fish ${Boost_LIBRARIES})
endif()