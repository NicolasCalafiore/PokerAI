//
// Created by Administrator on 8/9/2024.
//

#ifndef POKERAI_CARD_H
#define POKERAI_CARD_H
#include <random>

using namespace std;
class Card{
public:
    int value;
    int suite;

    Card(){
        random_device rd;
        uniform_int_distribution<> distr(0, 14);
        mt19937 gen(rd());
        uniform_int_distribution<> distra(0, 3);
        this->value = distr(gen);
        this->suite = distra(gen);
    }
};
#endif //POKERAI_CARD_H
