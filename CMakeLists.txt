# Setup base
cmake_minimum_required(VERSION 3.16)
project(opengl LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
include(Dependencies.cmake)

# Projects
add_subdirectory(App)
add_subdirectory(Core)
