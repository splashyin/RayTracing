cmake_minimum_required(VERSION 3.10)

project(RayTracing VERSION 1.0)

# specify the cxx standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add executable
add_executable(${PROJECT_NAME} main.cpp)

# include dir
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           )
