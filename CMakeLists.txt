cmake_minimum_required(VERSION 3.10.1)

project(tsl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
)

include_directories(3rdparty/rang)
include_directories(3rdparty/cxxopts)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9) # the commit hash for 1.5.0
FetchContent_MakeAvailable(cpr)

add_executable(tsl ${SOURCES})

target_link_libraries(tsl PRIVATE cpr::cpr)