cmake_minimum_required(VERSION 3.10.1)

project(tsl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(SOURCES
    src/main.cpp
)

include_directories(3rdparty/cxxopts)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b) # the commit hash for 1.6.2
FetchContent_MakeAvailable(cpr)

add_executable(tsl ${SOURCES})

target_link_libraries(tsl PRIVATE cpr::cpr)