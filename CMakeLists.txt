cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (ResourceSystem VERSION 1.0)

add_executable(test_rs main.cpp "include/Resource/Resource.h" "include/ResourceHandle/ResourceHandle.h")

add_subdirectory(libs/shader_lib)

target_link_libraries(test_rs shaderLib)