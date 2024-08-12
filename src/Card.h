//
// Created by Administrator on 8/9/2024.
//

#ifndef POKERAI_CARD_H
#define POKERAI_CARD_H
#include <random>
#include "../Utils/Utils.h"
#include "../Utils/Random.h"

using namespace std;
class Card{
public:
    int value;
    int suite;

    Card(){
        this->value = Random::randomInt(2, 14);
        this->suite = Random::randomInt(0, 3);
    }
};
#endif //POKERAI_CARD_H
