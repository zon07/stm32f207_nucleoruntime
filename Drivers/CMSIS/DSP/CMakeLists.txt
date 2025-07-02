cmake_minimum_required(VERSION 3.22)

project(cmsis_dsp)

# Настройки компилятора (используем те же флаги, что и в основном проекте)
include(../../../cmake/gcc-arm-none-eabi.cmake)

# Исходные файлы DSP
file(GLOB_RECURSE DSP_SOURCES
    "Source/*.c"
)

# Создаем статическую библиотеку
add_library(cmsis_dsp STATIC ${DSP_SOURCES})

# Подключаем заголовочные файлы
target_include_directories(cmsis_dsp PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../Include"
)

# Флаги компиляции
target_compile_definitions(cmsis_dsp PUBLIC
    ARM_MATH_CM3
)

# Оптимизация для Release
set_target_properties(cmsis_dsp PROPERTIES
    INTERFACE_POSITION_INDEPENDENT_CODE ON
)