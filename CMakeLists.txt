cmake_minimum_required(VERSION 3.16)

project(
    matrix
    VERSION 0.0.1
    DESCRIPTION "matrixlib  "
    LANGUAGES CXX
)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Тип сборки по умолчанию
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Исходники
set(SOURCES
    src/matrix.cpp
    src/c_api.cpp

)

add_library(static-matrixlib STATIC ${SOURCES})

# Включаем заголовочные файлы fmt
find_package(fmt REQUIRED)
target_link_libraries(static-matrixlib PRIVATE fmt::fmt)

# Указываем include-директории
target_include_directories(static-matrixlib
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        ${PROJECT_SOURCE_DIR}/include
)
        
 set_target_properties(static-matrixlib PROPERTIES PREFIX "")      

