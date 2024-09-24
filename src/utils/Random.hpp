#pragma once
#include <random>
#include <chrono>

class Random {
public:
    static void init();
    static int getInt(int min, int max);
    static float getFloat(float min, float max);
    static bool getBool(float trueProbability = 0.5f);

private:
    static std::mt19937 generator;
};