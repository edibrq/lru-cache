#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "LRUCache.h"

TEST_CASE("LRUCache functionality") {
    LRUCache cache(2);

    SECTION("Basic operations") {
        cache.put(1, 1);
        cache.put(2, 2);
        REQUIRE(cache.get(1) == 1);
        cache.put(3, 3);
        REQUIRE(cache.get(2) == -1);
        cache.put(4, 4);
        REQUIRE(cache.get(1) == -1);
        REQUIRE(cache.get(3) == 3);
        REQUIRE(cache.get(4) == 4);
    }
}

