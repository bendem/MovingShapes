#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random {

public:
    Random();

    unsigned long nextUnsigned(unsigned long);

private:
    std::default_random_engine engine;

};

#endif
