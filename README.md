# LRU Cache Implementation

This project implements an LRU (Least Recently Used) cache in C++ using a doubly linked list and an unordered map. The project is set up with CMake and includes unit tests using Catch2.

## Prerequisites

- CMake 3.14 or higher
- A C++17 compatible compiler

## Building the Project

1. Clone the repository:

```bash
git clone <repository-url> cd <repository-directory>
```

2. Create a build directory and run CMake:

```bash
mkdir build
cd build
cmake ..
```

3. Build the project:

```bash
cmake --build .
```

## Running Tests

To run the unit tests, execute the following command in the `build` directory:
```bash
ctest
```

## Dependencies

Dependencies are managed using [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake). The project automatically downloads and configures Catch2 for unit testing.

