# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "~/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(RP2040_6bit_Micropad C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(RP2040_6bit_Micropad main.c)

# Add the standard library to the build
target_link_libraries(RP2040_6bit_Micropad pico_stdlib)

pico_enable_stdio_uart(RP2040_6bit_Micropad 0)
pico_enable_stdio_usb(RP2040_6bit_Micropad 1)

pico_add_extra_outputs(RP2040_6bit_Micropad)

