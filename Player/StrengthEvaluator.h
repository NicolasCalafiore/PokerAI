//
// Created by Administrator on 8/9/2024.
//

#ifndef POKERAI_STRENGTHEVALUATOR_H
#define POKERAI_STRENGTHEVALUATOR_H
#include <tuple>
#include "../src/Card.h"
#include <set>
#include <iostream>
#include <map>

using namespace std;
class StrengthEvaluator{
public:
    int highCard;
    pair<bool, vector<int>> pair;
    std::pair<bool, vector<int>> threeOfAKind;
    std::pair<bool, vector<int>> straight;
    std::pair<bool, int> flush;
    std::pair<bool, int> fullHouse;
    std::pair<bool, int> fourOfAKind;
    std::pair<bool, int> straightFlush;
    bool royalFlush = false;

    StrengthEvaluator(){
        highCard = 0;
        pair = {false, {}};
        threeOfAKind = {false, {}};
        straight = {false, {}};
        flush = {false, 0};
        fullHouse = {false, 0};
        fourOfAKind = {false, 0};
        straightFlush = {false, 0};
    }

    void EvaluateHighCard(vector<Card> cards){
        highCard = cards[cards.size() - 1].value;
    }

    void EvaluatePair(vector<Card> cards) {
        for (int i = 1; i < cards.size(); i++)
            if (cards[i].value == cards[i - 1].value) {
                pair.first = true;
                pair.second.push_back(cards[i].value);
                i++;
            }
    }

    void EvaluateTuple(vector<Card> cards) {
        for (int i = 2; i < cards.size(); i++)
            if (cards[i].value == cards[i - 1].value && cards[i - 1].value == cards[i - 2].value) {
                threeOfAKind.first = true;
                threeOfAKind.second.push_back(cards[i].value);
                i += 2;
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

    void EvaluateFullHouse(vector<Card> cards) {
        if (threeOfAKind.first && pair.first && threeOfAKind.second != pair.second) {
            fullHouse.first = true;
            fullHouse.second = max(threeOfAKind.second[0], pair.second[0]);
        }
        else
            fullHouse.first = false;
    }


    void EvaluateFlush(vector<Card> cards){
        int counter = 0;
        for(int i = 0; i < cards.size(); i++)
            if(cards[i].suite == cards[i + 1].suite)
                counter++;

        flush.first = counter >= 5;
        flush.second = highCard;
    }

    void EvaluateFourOfAKind(vector<Card> cards) {
        for (int i = 3; i < cards.size(); i++) {
            if (cards[i].value == cards[i - 1].value && cards[i - 1].value == cards[i - 2].value && cards[i - 2].value == cards[i - 3].value) {
                fourOfAKind.first = true;
                fourOfAKind.second = cards[i].value;
                return;
            }
        }
        fourOfAKind.first = false;
        fourOfAKind.second = 0;
    }


    void EvaluateStraightFlush(vector<Card> cards){
        int highestCard = 0;
        map<int, int> suitMapper = {{0,0},{1,0},{2,0},{3,0}};
        int targetSuite;
        if(straight.first){
            for(auto i : cards){
                suitMapper[i.suite] += 1;
            }
            for(auto i : suitMapper)
                if(i.second >= 5) {
                    targetSuite = i.first;
                    straightFlush.first = true;
                }
            for(auto i : cards){
                if(i.suite == targetSuite)
                    if(i.value > highestCard)
                        highestCard = i.value;
            }
            straightFlush.second = highestCard;
        }
    }

    void EvaluateRoyalFlush(vector<Card> cards){
        if(straightFlush.first){
            if(straight.second[straight.second.size() - 1] == 14)
                royalFlush = true;
        }
    }

    int GetHandStrength(){                                      //MIN - MAX
        if(royalFlush)
            return highCard + 14 * 8;
        else if(straightFlush.first)
            return straightFlush.second + 14 * 7;
        else if (fourOfAKind.first)
            return fourOfAKind.second + 14 * 6;
        else if (fullHouse.first)
            return fullHouse.second + 14 * 5;
        else if(flush.first)
            return flush.second + 14 * 4;
        else if (straight.first)
            return Utils::GetHighest(straight.second) + 14 * 3;
        else if(threeOfAKind.first)
            return Utils::GetHighest(threeOfAKind.second) + 14 * 2;
        else if(pair.first)
            return Utils::GetHighest(pair.second) + 14;
        else return highCard;
    }
};
#endif //POKERAI_STRENGTHEVALUATOR_H
