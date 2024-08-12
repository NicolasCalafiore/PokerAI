//
// Created by Administrator on 8/10/2024.
//
#include <iostream>
#include <string>
#include "../src/Game.h"
#include <map>

#ifndef POKERAI_OUTPUTINTERFACE_H
#define POKERAI_OUTPUTINTERFACE_H
using namespace std;
static map<int, string> cardMapper = {{14,"A"},{13,"K"},{12,"Q"},
                                  {11,"J"},{10,"10"},{9,"9"},
                                  {8,"8"},{7,"7"},{6,"6"},
                                  {5,"5"},{4,"4"},{3,"3"},{2,"2"}};

static map<int, string> suiteMapper = {{0, "S"},{1,"H"},{2, "C"},{3, "D"}};
class OutputInterface{

public:
    static void PrintCommunityCards(Game& game){
        cout << "Community Cards: ";
        for(auto i : game.communityCards)
            PrintCard(i);
        cout << endl;
    }
    static void PrintPlayerCards(Game& game){
        for(auto i : game.players){
            cout << "Player: " << i->id << ": ";
            PrintCard(i->cards.first);
            PrintCard(i->cards.second);
            cout << endl;
        }
    }
    static void PrintHandStrengths(Game& game){
        cout << endl << "Player Evaluations" << endl;
        for(auto player : game.players){
            cout << "Player " << player->id << " (" << player->strength << ")";
            if(player->evaluator.royalFlush)
                cout << ": Royal Flush" << endl;
            else if(player->evaluator.straightFlush.first)
                cout << ": Straight Flush" << endl;
            else if(player->evaluator.fourOfAKind.first)
                cout << ": Four of a Kind" << endl;
            else if(player->evaluator.fullHouse.first)
                cout << ": Full House" << endl;
            else if(player->evaluator.flush.first)
                cout <<  ": Flush" << endl;
            else if(player->evaluator.straight.first)
                cout << ": Straight" << endl;
            else if(player->evaluator.threeOfAKind.first)
                cout << ": Three of a Kind" << endl;
            else if(player->evaluator.pair.first)
                cout << ": Pair " << endl;
            else
                cout << ": High Card (" << player->evaluator.highCard << ")" << endl;
        }
    }
    static void PrintCard(Card& i){
        cout << "[" << cardMapper[i.value] << " | " << suiteMapper[i.suite] << "] ";
    }
};
#endif //POKERAI_OUTPUTINTERFACE_H
