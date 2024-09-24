#include "Random.hpp"

std::mt19937 Random::generator;

void Random::init() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::mt19937(seed);
}

int Random::getInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

float Random::getFloat(float min, float max) {
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator);
}

bool Random::getBool(float trueProbability) {
    std::bernoulli_distribution distribution(trueProbability);
    return distribution(generator);
}