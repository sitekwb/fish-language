cmake_minimum_required(VERSION 3.15)

project(Fish)

include_directories(include include/* include/*/* include/*/*/* include/*/*/*/* include/*/*/*/*/*)

find_package(Boost 1.45.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread -Wno-writable-strings")

file(GLOB SOURCES "source/Analizator/*/*.cpp")
file(GLOB SOURCES2 "source/*.cpp")
set(SOURCES ${SOURCES} ${SOURCES2})

file(GLOB S_TESTS "source/Tests/*.cpp")
file(GLOB S_PROGRAM_OPTIONS "source/ProgramOptions/*.cpp")

message("${CMAKE_CXX_STANDARD_LIBRARIES}")
add_executable(Fish main.cpp ${SOURCES} ${S_PROGRAM_OPTIONS})
#add_executable(FishBoostTest ${SOURCES} ${S_TESTS})

if(Boost_FOUND)
    target_link_libraries(Fish ${Boost_LIBRARIES})
endif()