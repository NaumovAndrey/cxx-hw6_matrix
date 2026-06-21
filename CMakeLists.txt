cmake_minimum_required(VERSION 3.16)

project(
    matrix
    VERSION 0.0.1
    DESCRIPTION "matrixlib"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)

set(SOURCES
    src/matrix.cpp
    src/c_api.cpp
)

include(GenerateExportHeader)

find_package(fmt REQUIRED)

# --- Статическая библиотека ---
add_library(static-matrixlib STATIC ${SOURCES})

generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

target_link_libraries(static-matrixlib PRIVATE fmt::fmt)
target_include_directories(static-matrixlib PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(
    static-matrixlib
    PUBLIC
        MATH_STATIC_DEFINE
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(static-matrixlib PROPERTIES PREFIX "")

# --- Динамическая библиотека ---
add_library(shared_matrixlib SHARED ${SOURCES})

target_compile_definitions(shared_matrixlib PRIVATE "LINKAGE=extern \"C\"")

set_target_properties(shared_matrixlib PROPERTIES VISIBILITY_INLINES_HIDDEN YES)

generate_export_header(
    shared_matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)

target_link_libraries(shared_matrixlib PRIVATE fmt::fmt)
target_include_directories(shared_matrixlib PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(
    shared_matrixlib
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(shared_matrixlib PROPERTIES PREFIX "")

# Подключение статической библиотеки
add_executable(
    test-static-matrix
    src/test/test-static-matrix.cpp
)

target_include_directories(test-static-matrix PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(test-static-matrix PRIVATE static-matrixlib)

# Подключение динамической библиотеки
add_executable(
    test-shared-matrix
    src/test/test-shared-matrix.cpp
)

target_include_directories(test-shared-matrix PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(test-shared-matrix PRIVATE shared_matrixlib)
