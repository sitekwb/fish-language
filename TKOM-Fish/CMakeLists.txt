cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/* include/*/*/*/*/*)

find_package(Boost 1.45.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

file(GLOB S_ANALIZATOR "source/Analizator/*.cpp")
file(GLOB S_SYMBOLS "source/Analizator/Symbols/*.cpp")
file(GLOB S_TOKENS "source/Analizator/Tokens/*.cpp")
file(GLOB S_SOURCES "source/Sources/*.cpp")
file(GLOB S_INTERPRETER "source/Analizator/Interpreter/*.cpp")
file(GLOB S_GLOBAL "source/*.cpp")
set(SOURCES ${S_ANALIZATOR} ${S_SYMBOLS} ${S_TOKENS} ${S_SOURCES} ${S_INTERPRETER} ${S_GLOBAL})

file(GLOB S_TESTS "source/Tests/*.cpp")
file(GLOB S_PROGRAM_OPTIONS "source/ProgramOptions/*.cpp")

message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${SOURCES} ${S_PROGRAM_OPTIONS})
add_executable(FishBoostTest ${SOURCES} ${S_TESTS})
add_executable(QuickTest quickTestMain.cpp ${SOURCES})

if(Boost_FOUND)
    target_link_libraries(Fish ${Boost_LIBRARIES})
endif()