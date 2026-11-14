cmake_minimum_required(VERSION 4.3.1)
project(block_slaughter VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 3.6.0 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(game)
