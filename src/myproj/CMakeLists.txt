cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT_DIR_NAME ${CMAKE_SOURCE_DIR} NAME)

project($(PROJECT_DIR_NAME))

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

