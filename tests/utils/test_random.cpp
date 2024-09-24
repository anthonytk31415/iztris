#include <catch2/catch_test_macros.hpp>
#include "../../src/utils/Random.hpp"

TEST_CASE("Random number generation", "[random]") {
    Random::init();  // Initialize the random number generator

    SECTION("Generate random integer within range") {
        int min = 1;
        int max = 10;
        for (int i = 0; i < 100; ++i) {
            int result = Random::getInt(min, max);
            REQUIRE(result >= min);
            REQUIRE(result <= max);
        }
    }

    // Add more test cases for your Random class here
}