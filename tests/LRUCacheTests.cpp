#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "LRUCache.h"

TEST_CASE("LRUCache basic functionality") {
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

TEST_CASE("LRUCache edge cases") {
    LRUCache cache(1);

    SECTION("Single element cache") {
        cache.put(1, 1);
        REQUIRE(cache.get(1) == 1);
        cache.put(2, 2);
        REQUIRE(cache.get(1) == -1);
        REQUIRE(cache.get(2) == 2);
    }

    SECTION("Empty cache access") {
        REQUIRE(cache.get(10) == -1);
    }
}

TEST_CASE("LRUCache capacity handling") {
    LRUCache cache(3);

    SECTION("Capacity overflow") {
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3);
        cache.put(4, 4); // This should evict key 1
        REQUIRE(cache.get(1) == -1);
        REQUIRE(cache.get(2) == 2);
        REQUIRE(cache.get(3) == 3);
        REQUIRE(cache.get(4) == 4);
    }
}

TEST_CASE("LRUCache update existing key") {
    LRUCache cache(2);

    SECTION("Update existing key") {
        cache.put(1, 1);
        cache.put(1, 10);
        REQUIRE(cache.get(1) == 10);
    }
}

TEST_CASE("LRUCache frequent access") {
    LRUCache cache(2);

    SECTION("Frequent access keeps item in cache") {
        cache.put(1, 1);
        cache.put(2, 2);
        REQUIRE(cache.get(1) == 1); // Access 1 to make it recently used
        cache.put(3, 3); // This should evict key 2
        REQUIRE(cache.get(1) == 1);
        REQUIRE(cache.get(2) == -1);
        REQUIRE(cache.get(3) == 3);
    }
}

TEST_CASE("LRUCache larger capacity") {
    LRUCache cache(5);

    SECTION("Handling larger capacity") {
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3);
        cache.put(4, 4);
        cache.put(5, 5);
        REQUIRE(cache.get(1) == 1);
        cache.put(6, 6); // This should evict key 2
        REQUIRE(cache.get(2) == -1);
        REQUIRE(cache.get(3) == 3);
        REQUIRE(cache.get(4) == 4);
        REQUIRE(cache.get(5) == 5);
        REQUIRE(cache.get(6) == 6);
    }
}

TEST_CASE("LRUCache test that fails") {
    LRUCache cache(2);

    SECTION("Intentional failure") {
        cache.put(1, 1);
        cache.put(2, 2);
        REQUIRE(cache.get(1) == 2); // This is intended to fail
    }
}
