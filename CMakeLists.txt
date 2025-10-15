cmake_minimum_required(VERSION 3.16)

project(
    matrix
    VERSION 0.0.1
    DESCRIPTION "hw6_modul_cpp"
    LANGUAGES CXX
)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходники
set(SOURCES
    src/main.cpp
    src/matrix.cpp
    
)

# Создаем исполняемый файл (название совпадает с именем проекта)
add_executable(matrix ${SOURCES})

# Включаем заголовочные файлы fmt
find_package(fmt REQUIRED)
target_link_libraries(matrix PRIVATE fmt::fmt)

# Указываем include-директории
target_include_directories(matrix PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Тип сборки по умолчанию
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()