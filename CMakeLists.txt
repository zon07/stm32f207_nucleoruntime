cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME Stm32F207_NucleoRuntime)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)


# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
    ${CMAKE_SOURCE_DIR}/libs
)


# Рекурсивно находим все .c файлы в SimulinkApp и подпапках
file(GLOB_RECURSE SIMULINK_SOURCES 
    "./SimulinkApp/*.c"
)

# Рекурсивно находим все .h файлы для добавления include директорий
file(GLOB_RECURSE SIMULINK_HEADERS 
    "./SimulinkApp/*.h"
)

# Получаем уникальные директории из списка заголовочных файлов
foreach(HEADER ${SIMULINK_HEADERS})
    get_filename_component(DIR ${HEADER} DIRECTORY)
    list(APPEND SIMULINK_INCLUDE_DIRS ${DIR})
endforeach()
list(REMOVE_DUPLICATES SIMULINK_INCLUDE_DIRS)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ./Xcp/XcpApplication.c
    ./Xcp/XcpBasic.c
    ./Xcp/XcpPort.c
    # Добавляем исходники CMSIS-DSP
    ${CMSIS_DSP_SOURCES}
    # Добавляем все найденные исходники Simulink
    ${SIMULINK_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ./Xcp/
    # Добавляем путь к PrivateInclude CMSIS-DSP
    ./Drivers/CMSIS/DSP/Include
    # Добавляем все найденные include директории Simulink
    ${SIMULINK_INCLUDE_DIRS}
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
    ARM_MATH_CM3  # Для CMSIS-DSP
)

# Генерация .hex и .bin файлов
set(ARTIFACTS_DIR "${CMAKE_SOURCE_DIR}/firmwareFiles")
file(MAKE_DIRECTORY ${ARTIFACTS_DIR})

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${ARTIFACTS_DIR}/${CMAKE_PROJECT_NAME}.hex
    COMMENT "Generating HEX file"
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${ARTIFACTS_DIR}/${CMAKE_PROJECT_NAME}.bin
    COMMENT "Generating BIN file"
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    cmsis_dsp
    # Add user defined libraries
)
