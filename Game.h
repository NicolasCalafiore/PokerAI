//
// Created by Administrator on 8/9/2024.
//
#include <vector>
#ifndef POKERAI_GAME_H
#define POKERAI_GAME_H

#include "Player.h"
#include <random>

using namespace std;
class Game{
public:
    vector<Player*> players;
    random_device rd;
    vector<Card> communityCards;

    Game(int numPlayers){

        for(int i = 0; i < numPlayers; i++)
            players.push_back(new Player(i));
    };

    void CreateHands(){
        for(auto& i : players)
            i->CreateHand();
    }

    void AddFlop(){
        uniform_int_distribution<> distr(0, 13);
        mt19937 gen(rd());
        communityCards.clear();
        for(int i = 0; i < 3; i++)
            communityCards.push_back(Card());
    }


    void EvaluateHands(){
        for(auto i : players)
            i->CalculateStrength(communityCards);
    }

    void AddTurnCard(){
        communityCards.push_back(Card());
    }


};
#endif //POKERAI_GAME_H
