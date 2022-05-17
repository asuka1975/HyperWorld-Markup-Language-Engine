cmake_minimum_required(VERSION 3.16)

project(HyperWorld_Markup_Language_Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")

add_executable(HyperWorld_Markup_Language_Engine src/main.cpp)
target_include_directories(HyperWorld_Markup_Language_Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)