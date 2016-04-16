cmake_minimum_required (VERSION 2.8.12.2)
project (hello_world)

set(CMAKE_CXX_FLAGS "-g -Wall")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

# include directory for headers
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(satellite ${SOURCES})
