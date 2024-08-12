//
// Created by Administrator on 8/9/2024.
//
#include<vector>
#include "../Utils/Utils.h"
#include "../src/Card.h"
#include "StrengthEvaluator.h"

#ifndef POKERAI_PLAYER_H
#define POKERAI_PLAYER_H

using namespace std;
class Player{
public:
    int id;
    int wallet = 100;
    float strength;
    pair<Card, Card> cards;
    StrengthEvaluator evaluator;

    Player(int id){
        this->id = id;
    }

    void CreateHand(){
        this->cards.first = Card();
        this->cards.second = Card();
    }


    void CalculateStrength(vector<Card> pot){
        vector<Card> allCards = Utils::combine(pot, {cards.first, cards.second});
        Utils::SortCards(allCards);
        StartEvaluation(allCards);
        strength = evaluator.GetHandStrength();
    }

    void StartEvaluation(vector<Card> allCards){
        evaluator.EvaluateHighCard(allCards);
        evaluator.EvaluatePair(allCards);
        evaluator.EvaluateTuple(allCards);
        evaluator.EvaluateStraight(allCards);
        evaluator.EvaluateFlush(allCards);
        evaluator.EvaluateFullHouse(allCards);
        evaluator.EvaluateFourOfAKind(allCards);
        evaluator.EvaluateStraightFlush(allCards);
        evaluator.EvaluateRoyalFlush(allCards);
    }

    void CalculateBet(){

    }
};
#endif //POKERAI_PLAYER_H
