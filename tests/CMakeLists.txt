include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(LRUCacheTests LRUCacheTests.cpp)
target_link_libraries(LRUCacheTests LRUCache Catch2::Catch2WithMain)

# Register the test executable with CTest
add_test(NAME LRUCacheTests COMMAND LRUCacheTests)
