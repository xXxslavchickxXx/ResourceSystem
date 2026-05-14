cmake_minimum_required(VERSION 3.20)
project(ResourceSystem VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============ Библиотеки ============

set(RESOURCE_LIB_CPP
    src/ResourceManager/ResourceSpecializations.cpp
)
set(RESOURCE_LIB_HEADERS
    include/Resource/Resource.h
    include/ResourceManager/ResourceManager.h
    include/ResourceManager/ResourceManager.inl
)

# 1. Header-only библиотека ресурсов
add_library(RSystemLib STATIC
    ${RESOURCE_LIB_CPP}
    ${RESOURCE_LIB_HEADERS}
)
target_include_directories(RSystemLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

option(RESOURCE_SYSTEM_EXAMPLE OFF)
if(RESOURCE_SYSTEM_EXAMPLE)
    # 2. Библиотека с шейдерами
    add_subdirectory(libs/shader_lib)

    # 3. Библиотека с примером
    add_library(exampleLib example/exampleResourceClass/exampleResource.cpp)
    target_link_libraries(exampleLib PUBLIC RSystemLib shaderLib)
    target_include_directories(exampleLib PUBLIC example/exampleResourceClass)

    # ============ Исполняемый файл ============

    add_executable(test_rsEXE example/test.cpp)

    find_package(glfw3)
    target_link_libraries(test_rsEXE PUBLIC exampleLib glfw)

    # ============ Копирование ассетов ============

    add_custom_command(TARGET test_rsEXE POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/example/assets
            $<TARGET_FILE_DIR:test_rsEXE>/assets
        COMMENT "Copying assets"
    )
endif()