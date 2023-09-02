#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
using namespace std;

class Random{
    vector<int> v;
public:
    Random(int max); //initialize a random number generator, maximum value is max
    int generate();
};

#endif