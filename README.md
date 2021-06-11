# Air

This is a rendering server for [SoL](https://github.com/madmann91/sol).

## Building

In order to build Air, you're going to need a C++20-compatible compiler, CMake, and SoL.
First, make sure you have downloaded all the submodules, by running:

    git submodule update --init --recursive

Once that is done, Air can be built using the following commands:

    mkdir build
    cd build
    cmake -Dsol_DIR=</path/to/sol-config.cmake>
    cmake --build .

The file `sol-config.cmake` is generated by CMake when building SoL, and should be located in the directory where SoL has been built.
