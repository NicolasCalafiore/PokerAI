//
// Created by Administrator on 8/9/2024.
//

#ifndef POKERAI_STRENGTHEVALUATOR_H
#define POKERAI_STRENGTHEVALUATOR_H
#include <tuple>
#include "Card.h"
#include <set>
#include <iostream>
using namespace std;
class StrengthEvaluator{
public:
    pair<bool, set<int>> pair;
    std::pair<bool, set<int>> threeOfAKind;
    std::pair<bool, vector<int>> straight;
    bool flush = false;
    bool fullHouse = false;
    bool fourOfAKind = false;
    bool straightFlush = false;
    bool royalFlush = false;

    StrengthEvaluator(){

    }

    void EvaluatePair(vector<Card> cards){
        for(int i = 0; i < cards.size(); i++){
            for(int j = 0; j < cards.size(); j++){
                if(cards[i].value == cards[j].value && i != j){
                    pair.first = true;
                    pair.second.insert(cards[i].value);
                }
            }
        }
    }

    void EvaluateTuple(vector<Card> cards){
        for(int i = 0; i < cards.size(); i++){
            for(int j = 0; j < cards.size(); j++){
                for(int k = 0; k < cards.size(); k++){
                    if(cards[i].value == cards[j].value && cards[j].value == cards[k].value && i != j && j != k && i != k){
                        threeOfAKind.first = true;
                        threeOfAKind.second.insert(cards[i].value);
                    }
                }
            }
        }
    }

    void EvaluateStraight(vector<Card> cards) {
        int counter = 1;  // Start counting from the first card
        vector<int> values = {cards[0].value};

        for (int i = 1; i < cards.size(); i++) {
            if (cards[i].value == cards[i - 1].value + 1) {
                counter++;
                values.push_back(cards[i].value);
            } else if (cards[i].value != cards[i - 1].value) {
                // Reset counter if the sequence is broken
                counter = 1;
                values = {cards[i].value};
            }

            if (counter >= 5) {
                straight.first = true;
                straight.second = values;
                return;  // Early return as soon as a straight is detected
            }
        }

        straight.first = false;  // No straight found
        straight.second.clear();
    }

    void EvaluateFullHouse(vector<Card> cards){
        if(pair.first && threeOfAKind.first)
            if(pair.second != threeOfAKind.second)
                fullHouse = true;

        fullHouse = false;
    }

    void EvaluateFlush(vector<Card> cards){
        int counter = 0;
        for(int i = 0; i < cards.size(); i++){
            if(cards[i].suite == cards[i + 1].suite)
                counter++;
        }
        flush = counter >= 5;
    }

    void EvaluateFourOfAKind(vector<Card> cards){
        for(int i = 0; i < cards.size(); i++){
            for(int j = 0; j < cards.size(); j++){
                for(int k = 0; k < cards.size(); k++){
                    for(int l = 0; l < cards.size(); l++){
                        if(cards[i].value == cards[j].value && cards[j].value == cards[k].value && cards[k].value == cards[l].value && i != j && j != k && i != k && i != l && j != l && k != l){
                            fourOfAKind = true;
                        }
                    }
                }
            }
        }
    }

    void EvaluateStraightFlush(vector<Card> cards){
        if(straight.first){
            int counter = 0;
            for(int i = 0; i < cards.size(); i++){
                if(cards[i].suite == cards[i + 1].suite)
                    counter++;
            }
            straightFlush = counter >= 5;
        }
    }

    void EvaluateRoyalFlush(vector<Card> cards){
        if(straightFlush){
            if(straight.second[straight.second.size() - 1] == 14)
                royalFlush = true;
        }
    }

    void PrintHands(int id){
        cout << "Player: " << id << endl;

        if(pair.first) {
            cout << "Pairs: ";
            for(auto i : pair.second)
                cout << i << ", ";
            cout << endl;
        }

        if(threeOfAKind.first){
            cout << "Tuples: ";
            for(auto i : threeOfAKind.second)
                cout << i << ", ";
            cout << endl;
        }

        if(straight.first)
            cout << "Straight" << endl;

        if(flush)
            cout << "Flush" << endl;

        if(fullHouse)
            cout << "Full House" << endl;

        if(fourOfAKind)
            cout << "Four of a Kind" << endl;

        if(straightFlush)
            cout << "Straight Flush" << endl;

        if(royalFlush)
            cout << "Royal Flush" << endl;

        cout << endl << endl;
    }




};
#endif //POKERAI_STRENGTHEVALUATOR_H
