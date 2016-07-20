cmake_minimum_required(VERSION 2.8)
set(TARGET_NAME algorithms_tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file (GLOB TEST_SRC
        sorting/*.cpp
        )

file (GLOB LIBRARY_HEADERS
        sorting/*.h
        )

include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR})

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group("src" FILES ${LIBRARY_SRC})
source_group("include" FILES ${LIBRARY_HEADERS})

enable_testing()

link_directories(${LIBRARY_OUTPUT_DIRECTORY})

add_executable(${TARGET_NAME} ${TEST_SRC})

target_link_libraries(${TARGET_NAME}
        gtest
        gtest_main)
        #algorithms_lib)

add_test(NAME ${TARGET_NAME}
        COMMAND ${TARGET_NAME})