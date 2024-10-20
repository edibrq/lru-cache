#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Create and navigate to the build directory
mkdir -p build
cd build

# Run CMake to configure the project and generate the build system
cmake ..

# Build the project
cmake --build .

# Run tests
ctest
