#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std;

class Player{

    private:
        

    public:
        string name;

        Player(){}
        Player(string Pname);
        int stacksize();
        int cardesTaken();     
};

#endif