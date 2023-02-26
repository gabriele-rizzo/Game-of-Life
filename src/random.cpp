#include "random.hpp"

using namespace rd;

bool rd::random_bool(double probability)
{
    static random_device device;
    static mt19937 generator(device());
    static uniform_real_distribution<double> distribution(0, 1);
    return (distribution(generator) < probability);
}