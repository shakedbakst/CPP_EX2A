#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std;

class Player{

    private:
        string name;


    public:
        Player(){}
        Player(string Pname);
        int stacksize();
        int cardsTaken();     
};

#endif