cmake_minimum_required(VERSION 2.8)
project(zstream-cpp)

find_package(ZLIB REQUIRED)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")

include_directories("${CMAKE_SOURCE_DIR}/..")
include_directories(${ZLIB_INCLUDE_DIRS})

add_executable(output_test output_test.cpp)
target_link_libraries(output_test ${ZLIB_LIBRARIES})

add_executable(input_test input_test.cpp)
target_link_libraries(input_test ${ZLIB_LIBRARIES})

add_executable(buffer_test buffer_test.cpp)
target_link_libraries(buffer_test ${ZLIB_LIBRARIES})
