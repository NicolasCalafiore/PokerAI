#include <iostream>
#include "Game.h"


using namespace std;
int main() {
    vector<Card> cards;
    while(true) {
        Game game(1);
        game.CreateHands();
        game.AddFirstRoundCards();
        game.AddTurnCard();
        game.AddTurnCard();

//        game.PrintPotCards();
//        game.PrintPlayerCards();
        game.EvaluateHands();
        cards = game.potCards;
        cards.push_back(game.players[0]->cards.first);
        cards.push_back(game.players[0]->cards.second);
        if(game.players[0]->evaluator.royalFlush) break;
        cards.clear();
    }
    cout << "ROYAL FLUSH" << endl;
    for(auto i : cards)
        cout << i.value << ", ";
    return 0;
}
