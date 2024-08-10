//
// Created by Administrator on 8/9/2024.
//
#include<vector>
#include "Utils.h"
#include "Card.h"
#include "StrengthEvaluator.h"

#ifndef POKERAI_PLAYER_H
#define POKERAI_PLAYER_H

using namespace std;
class Player{
public:
    int id;
    int wallet;
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

    void PrintCards(){
        cout << "Player: " << id << endl;
        cout << "Cards: " << cards.first.value << ", " << cards.second.value << endl;
    }

    void CalculateStrength(vector<Card> pot){
        vector<Card> allCards = pot;
        allCards.push_back(cards.first);
        allCards.push_back(cards.second);
        Utils::SortCards(allCards);
        evaluator.EvaluatePair(allCards);
        evaluator.EvaluateTuple(allCards);
        evaluator.EvaluateStraight(allCards);
        evaluator.EvaluateFlush(allCards);
        evaluator.EvaluateFullHouse(allCards);
        evaluator.EvaluateFourOfAKind(allCards);
        evaluator.EvaluateStraightFlush(allCards);
        evaluator.EvaluateRoyalFlush(allCards);
        //evaluator.PrintHands(id);
    }
};
#endif //POKERAI_PLAYER_H
