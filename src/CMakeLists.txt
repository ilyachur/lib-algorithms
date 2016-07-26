cmake_minimum_required(VERSION 2.8)
set(TARGET_NAME algorithms_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file (GLOB LIBRARY_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sorting/*.cpp
        )

file (GLOB LIBRARY_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/sorting/*.h
        )

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group("src" FILES ${LIBRARY_SRC})
source_group("include" FILES ${LIBRARY_HEADERS})


#add_library(${TARGET_NAME} STATIC ${LIBRARY_SRC} ${LIBRARY_HEADERS})
#set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)