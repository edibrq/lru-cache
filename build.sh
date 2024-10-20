#!/bin/bash

set -e

mkdir -p build

cd build

# Run CMake to configure the project and generate the build system
cmake ..

# Build the project
cmake --build .

# Run tests
ctest
