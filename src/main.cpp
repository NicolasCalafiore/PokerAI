#include <iostream>
#include "Game.h"
#include "../Utils/OutputInterface.h"


using namespace std;

void DebugGame();

int main() {
//    Game game(3);
//    game.CreateHands();
//    game.AddFlop();
//    game.EvaluateHands();
//    OutputInterface::PrintCommunityCards(game);
//    OutputInterface::PrintPlayerCards(game);
//    OutputInterface::PrintHandStrengths(game);
    DebugGame();
    return 0;
}

void DebugGame(){
    vector<Card> allCards;
    int gameCount = 0;
    while(true){
        Game game(1);

        game.CreateHands();
        game.AddFlop();
        game.AddTurnCard();
        game.AddTurnCard();
        game.EvaluateHands();
        gameCount++;

        bool condition = game.players[0]->evaluator.royalFlush;

        if(condition){
            allCards = Utils::combine(game.communityCards, {game.players[0]->cards.first, game.players[0]->cards.second});
            break;
        }
    }

    Utils::SortCards(allCards);
    cout << "Game Count: " << gameCount << endl;
    for(auto i : allCards)
        OutputInterface::PrintCard(i);

}
