cmake_minimum_required(VERSION 3.16)

project(
    matrix
    VERSION 0.0.1
    DESCRIPTION "Matrix library"
    LANGUAGES CXX
)

# Общие настройки
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

option(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)

include(GenerateExportHeader)

# Исходные файлы
set(MATRIX_SOURCES
    src/matrix.cpp
    src/c_api.cpp
)

# Общая функция настройки библиотеки
function(configure_matrix_library TARGET)

    target_include_directories(${TARGET}
        PUBLIC
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    target_compile_features(${TARGET}
        PUBLIC
            cxx_std_20
    )

    target_compile_definitions(${TARGET}
        PUBLIC
            "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
    )

    set_target_properties(${TARGET}
        PROPERTIES
            PREFIX ""
    )

endfunction()

# Статическая библиотека
add_library(matrixlib_static STATIC
    ${MATRIX_SOURCES}
)

configure_matrix_library(matrixlib_static)

target_compile_definitions(matrixlib_static
    PUBLIC
        MATRIXLIB_STATIC_DEFINE
)

# Динамическая библиотека
add_library(matrixlib_shared SHARED
    ${MATRIX_SOURCES}
)

configure_matrix_library(matrixlib_shared)

generate_export_header(matrixlib_shared
    BASE_NAME MATRIXLIB
    EXPORT_FILE_NAME
        "${PROJECT_BINARY_DIR}/matrixlib_export.h"
)

set_target_properties(matrixlib_shared
    PROPERTIES
        VISIBILITY_INLINES_HIDDEN YES
)

# Тест статической библиотеки
add_executable(test-static-matrix
    src/test/test-static-matrix.cpp
)

target_link_libraries(test-static-matrix
    PRIVATE
        matrixlib_static
)

# Тест динамической библиотеки
add_executable(test-shared-matrix
    src/test/test-shared-matrix.cpp
)

target_link_libraries(test-shared-matrix
    PRIVATE
        matrixlib_shared
)