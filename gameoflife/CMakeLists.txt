cmake_minimum_required(VERSION 3.12)
project(gameoflife C)

set(CMAKE_C_STANDARD 99)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(gameoflife main.c game_of_life.c game_of_life.h)
target_link_libraries(gameoflife ${GTK3_LIBRARIES})
target_link_libraries(gameoflife m)

add_executable(test test.c)
target_link_libraries(test m)