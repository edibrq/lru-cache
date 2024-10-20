add_library(LRUCache LRUCache.cpp)
add_executable(main main.cpp)
target_link_libraries(main LRUCache)
