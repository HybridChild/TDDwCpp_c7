cmake_minimum_required(VERSION 3.20.0)

project(chapter7)

add_subdirectory(library)
add_subdirectory(libraryTest)

install_programs(. FILES out/build/libraryTest/test)
