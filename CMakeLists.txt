cmake_minimum_required(VERSION 3.6)
project(mdot_max44009)

set(CMAKE_CXX_STANDARD 11)

# Take those from mbed-os/targets/targets.json for your particular target.
# Below are xdot device features.
# This allows your CLion IDE to identify I2C, Serial etc and avoid "Can't resolve type" warnings.
add_definitions(
        -DDEVICE_ANALOGIN=1
        -DDEVICE_I2C=1
        -DDEVICE_I2CSLAVE=1
        -DDEVICE_I2C_ASYNCH=1
        -DDEVICE_INTERRUPTIN=1
        -DDEVICE_PORTIN=1
        -DDEVICE_PORTINOUT=1
        -DDEVICE_PORTOUT=1
        -DDEVICE_PWMOUT=1
        -DDEVICE_RTC=1
        -DDEVICE_SERIAL=1
        -DDEVICE_SLEEP=1
        -DDEVICE_SPI=1
        -DDEVICE_SPISLAVE=1
        -DDEVICE_SPI_ASYNCH=1
        -DDIVECE_STDIO_MESSAGES=1
)

include_directories(
        MAX44009
        mbed-os
        mbed-os/cmsis
        mbed-os/cmsis/TOOLCHAIN_GCC
        mbed-os/drivers
        mbed-os/events
        mbed-os/events/equeue
        mbed-os/features
        mbed-os/features/filesystem
        mbed-os/features/filesystem/bd
        mbed-os/features/filesystem/fat
        mbed-os/features/filesystem/fat/ChaN
        mbed-os/features/frameworks
        mbed-os/features/frameworks/greentea-client
        mbed-os/features/frameworks/greentea-client/greentea-client
        mbed-os/features/frameworks/greentea-client/source
        mbed-os/features/frameworks/unity
        mbed-os/features/frameworks/unity/source
        mbed-os/features/frameworks/unity/unity
        mbed-os/features/frameworks/utest
        mbed-os/features/frameworks/utest/source
        mbed-os/features/frameworks/utest/utest
        mbed-os/features/mbedtls
        mbed-os/features/mbedtls/importer
        mbed-os/features/mbedtls/inc
        mbed-os/features/mbedtls/inc/mbedtls
        mbed-os/features/mbedtls/platform
        mbed-os/features/mbedtls/platform/inc
        mbed-os/features/mbedtls/platform/src
        mbed-os/features/mbedtls/src
        mbed-os/features/mbedtls/targets
        mbed-os/features/mbedtls/targets/TARGET_STM
        mbed-os/features/mbedtls/targets/TARGET_STM/TARGET_STM32F4
        mbed-os/features/nanostack
        mbed-os/features/netsocket
        mbed-os/features/storage
        mbed-os/hal
        mbed-os/hal/storage_abstraction
        mbed-os/platform
        mbed-os/rtos
        mbed-os/rtos/rtx
        mbed-os/rtos/rtx/TARGET_CORTEX_M
        mbed-os/rtos/rtx/TARGET_CORTEX_M/TARGET_RTOS_M4_M7
        mbed-os/rtos/rtx/TARGET_CORTEX_M/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC
        mbed-os/targets
        mbed-os/targets/TARGET_STM
        mbed-os/targets/TARGET_STM/TARGET_STM32F4
        mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_MTS_MDOT_F411RE
        mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_MTS_MDOT_F411RE/device
        mbed-os/targets/TARGET_STM/TARGET_STM32F4/TARGET_MTS_MDOT_F411RE/device/TOOLCHAIN_GCC_ARM
        mbed-os/targets/TARGET_STM/TARGET_STM32F4/device
)

set(SOURCE_FILES main.cpp)

add_executable(mdot_max44009 ${SOURCE_FILES})