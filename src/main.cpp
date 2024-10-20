#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    std::cout << lruCache.get(1) << std::endl;  // Output: 1
    lruCache.put(3, 3);
    std::cout << lruCache.get(2) << std::endl;  // Output: -1
    lruCache.put(4, 4);
    std::cout << lruCache.get(1) << std::endl;  // Output: -1
    std::cout << lruCache.get(3) << std::endl;  // Output: 3
    std::cout << lruCache.get(4) << std::endl;  // Output: 4
    return 0;
}
