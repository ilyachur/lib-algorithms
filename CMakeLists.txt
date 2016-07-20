cmake_minimum_required(VERSION 2.8)
project(algorithms)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${LIBRARY_OUTPUT_DIRECTORY})

add_subdirectory(src)
add_subdirectory(test)