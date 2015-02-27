#include "utils/Random.hpp"

Random::Random() : engine(std::random_device()()) {
}

unsigned long Random::nextUnsigned(unsigned long bound) {
    return engine() % bound;
}
