//
// Created by Administrator on 8/9/2024.
//

#ifndef POKERAI_UTILS_H
#define POKERAI_UTILS_H
#include <vector>
#include "Card.h"

using namespace std;
class Utils{
public:
    static void SortCards(vector<Card>& cards){
        while(!IsSorted(cards))
            for (int i = 0; i < cards.size(); i++)
                for (int j = 0; j < cards.size(); j++)
                    if (cards[i].value < cards[j].value) {
                        Card temp = cards[i];
                        cards[i] = cards[j];
                        cards[j] = temp;
                    }

    }

    static bool IsSorted(vector<Card> cards){
        for(int i = 0; i < cards.size() - 1; i++)
            if(cards[i].value > cards[i + 1].value)
                return false;

        return true;
    }
};
#endif //POKERAI_UTILS_H
