Getting started with mDot using CLion on MacOS
====

# Prerequisites

1. [mDot Development Kit](https://www.multitech.com/brands/multiconnect-mdot)
2. [MAX44009 Ambient Light Sensor](https://datasheets.maximintegrated.com/en/ds/MAX44009.pdf)
3. [CLion IDE](https://www.jetbrains.com/clion/)

# Setup

Please follow [these steps](https://hackmd.io/JwBghgpgrAZgTAFgLQA4AmbhIVMBmJAIzAHYQkQ9SYJ9DMQg#System-packages).

# A new project

1. Create a new blank repo on github or bitbucket.
2. Clone that repo on your machine.
3. Change directory into it.
4. Activate your `virtualenv` containing the Mbed toolchain
5. `mbed new .`
6. Since the stable version of [libmdot](https://os.mbed.com/teams/MultiTech/code/libmDot-mbed5/shortlog/) requires the [mbed-os-5.4.7](https://github.com/ARMmbed/mbed-os/releases/tag/mbed-os-5.4.7) then let's use that:
    ```
    cd mbed-os && mbed update mbed-os-5.4.7
    ```

# Libraries
1. Go to the project's root folder.
3. `mbed add https://os.mbed.com/users/gizmo69the2nd/code/MAX44009/`

# CLion

Open the project with CLion IDE.

## Main

Create a hello world [`main.cpp`](https://github.com/sensidev/mdot-max44009/blob/master/main.cpp) in the root of the project.
  
## Ignores

1. Add a [`.gitignore`](https://github.com/sensidev/mdot-max44009/blob/master/.gitignore)
2. Add [`.mbedignore`](https://github.com/sensidev/mdot-max44009/blob/master/.mbedignore)


## Compile

`mbed compile -m mts_mdot_f411re -t GCC_ARM`

Expect to have a `BUILD` folder after compiling succeeds.

> Alternatively you can use the [flashit](https://github.com/sensidev/multitech-dot-flash) utility.
 
## CMakeList 

CLion uses the `CMakeLists.txt` file to enable its features. So:

1. Get all the folder paths you need from `BUILD/mts_mdot_f411re/GCC_ARM/.includes_***.txt`
2. Use CLion to Find with Regex `-I./(.*?)\s` & Replace `\n$1`
3. Use only the relative paths as arguments for `include_directories`
4. Addd definitions for the mDot board. 
    1. Take a look to `mbed-os/targets/targets.json`
    2. Get all required definisions from `MTS_MDOT_F411RE.device_has_add` - probably empty.
    3. Also check its inherits `FAMILY_STM32`.

Here's an example https://github.com/sensidev/xdot-blinky/blob/master/CMakeLists.txt

## Flash it

`cp ./BUILD/mts_mdot_f411re/GCC_ARM/your-repo-name.bin /Volumes/MULTITECH/`

> Alternatively you can use the [flashit](https://github.com/sensidev/multitech-dot-flash) utility.

# Serial

`screen /dev/cu.usbmodem142313 9600`

# Resources

1. https://github.com/ARMmbed/mbed-cli