cmake_minimum_required(VERSION 3.1)
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

add_executable(nocompression_test nocompression_test.cpp)
target_link_libraries(nocompression_test ${ZLIB_LIBRARIES})

# CREATE single header file

file(READ "${CMAKE_SOURCE_DIR}/../zstream_common.hpp" COMMON_CONTENT)
file(READ "${CMAKE_SOURCE_DIR}/../izstream.hpp" IZSTREAM_CONTENT)
file(READ "${CMAKE_SOURCE_DIR}/../izstream_impl.hpp" IZSTREAM_IMPL_CONTENT)
file(READ "${CMAKE_SOURCE_DIR}/../ozstream.hpp" OZSTREAM_CONTENT)
file(READ "${CMAKE_SOURCE_DIR}/../ozstream_impl.hpp" OZSTREAM_IMPL_CONTENT)

string(REPLACE "#include \"" "//#include \"" CONTENT "${COMMON_CONTENT} ${OZSTREAM_CONTENT} ${OZSTREAM_IMPL_CONTENT} ${IZSTREAM_CONTENT} ${IZSTREAM_IMPL_CONTENT}")

file(WRITE "${CMAKE_BINARY_DIR}/zstream.hpp" "${CONTENT}")
