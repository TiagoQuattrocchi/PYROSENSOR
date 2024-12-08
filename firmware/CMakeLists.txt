# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pyrosensor C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pyrosensor pyrosensor.c )

pico_set_program_name(pyrosensor "pyrosensor")
pico_set_program_version(pyrosensor "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(pyrosensor 0)
pico_enable_stdio_usb(pyrosensor 1)

add_library(max6675
    max6675/max6675.c
)

target_include_directories(max6675 PUBLIC
    max6675
)

target_link_libraries(max6675
    pico_stdlib
    hardware_spi
)

# Add the standard library to the build
target_link_libraries(pyrosensor
    pico_stdlib
)

# Add the standard include files to the build
target_include_directories(pyrosensor PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  max6675
)

# Add any user requested libraries
target_link_libraries(pyrosensor 
    hardware_adc
    hardware_pwm
    max6675
)

pico_add_extra_outputs(pyrosensor)

