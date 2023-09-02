#include "random.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

Random::Random(int max){
    for (int i = 1; i <= max; ++i){
	v.push_back(i);
    }
}

int Random::generate(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};
    shuffle( v.begin(), v.end(), rng );
    return v[0];
};
