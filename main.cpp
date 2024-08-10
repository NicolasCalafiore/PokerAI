#include <iostream>
#include "Game.h"
#include "OutputInterface.h"


using namespace std;
int main() {
    Game game(3);
    game.CreateHands();
    game.AddFlop();
    game.EvaluateHands();
    OutputInterface::PrintCommunityCards(game);
    OutputInterface::PrintPlayerCards(game);
    OutputInterface::PrintHandStrengths(game);
    return 0;
}
