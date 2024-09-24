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

    SECTION("Generate random float within range") {
        float min = 1.0f;
        float max = 10.0f;
        for (int i = 0; i < 100; ++i) {
            float result = Random::getFloat(min, max);
            REQUIRE(result >= min);
            REQUIRE(result <= max);
        }
    }

    SECTION("Generate random boolean with probability") {
        float trueProbability = 1.0f;
        for (int i = 0; i < 100; ++i) {
            bool result = Random::getBool(trueProbability);
            REQUIRE(result == true);
        }
    }

    SECTION("Generate random boolean with probability") {
        float trueProbability = 0.0f;
        for (int i = 0; i < 100; ++i) {
            bool result = Random::getBool(trueProbability);
            REQUIRE(result == false);
        }
    }
    // do we want to add some sort of test for the probability for the bernoulli distribution? TBD

}