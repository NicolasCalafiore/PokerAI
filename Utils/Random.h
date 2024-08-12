//
// Created by Administrator on 8/11/2024.
//

#ifndef POKERAI_RANDOM_H
#define POKERAI_RANDOM_H
#include <random>
using namespace std;
class Random{
public:
    static int randomInt(int min, int max){
        random_device rd;
        uniform_int_distribution<> distr(min, max);
        mt19937 gen(rd());
        return distr(gen);
    }
};
#endif //POKERAI_RANDOM_H
