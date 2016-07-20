cmake_minimum_required (VERSION 2.8)
set (TARGET_NAME  algorithms_tests)

#####################################################################################################
#                                     SETUP GOOGLE TESTS                                            #
#####################################################################################################
add_subdirectory(libs/gmock-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
#####################################################################################################
#                                     SETUP GOOGLE TESTS                                            #
#####################################################################################################
enable_testing()

add_subdirectory(unit)