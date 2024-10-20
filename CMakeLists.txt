cmake_minimum_required(VERSION 3.14)
project(LRUCacheProject)

set(CMAKE_CXX_STANDARD 17)

# Include FetchContent module
include(FetchContent)

# Fetch Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Add subdirectories
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

