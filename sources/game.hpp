#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "player.hpp"

using namespace std;

class Game{

    private:
      

    public:
        Player pl1;
        Player pl2;

        Game(){}
        Game(Player pl1, Player pl2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        
};

#endif