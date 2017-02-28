cmake_minimum_required(VERSION 3.5)

project(51)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
aux_source_directory(. SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})