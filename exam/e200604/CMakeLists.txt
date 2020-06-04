cmake_minimum_required(VERSION 3.12)

project(e200604 C)

set(CMAKE_C_STANDARD 99)


add_executable(f1 f1.c)
add_executable(f2 f2.c)
add_executable(f3 f3.c)
add_executable(f4 f4.c)
add_executable(f5 f5.c)
add_executable(f6 f6.c)
add_executable(f7 f7.c)
add_executable(f8 f8.c)
target_link_libraries(f8 m)
add_executable(f9 f9.c)
