#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"


using namespace std;

#1
TEST_CASE("Check players names"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(game.p1.name == "Alice");
    CHECK(game.p1.name == "Bob");
}

#2
TEST_CASE("How many cards each player has at the start of game"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

#3
TEST_CASE("How many cards each player has after 1 turn"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    CHECK((p1.stacksize() <= 25 || p2.stacksize() <= 25));
    CHECK((p2.cardesTaken() => 1 || p2.cardesTaken() => 1));
}

#4
TEST_CASE("How many cards each player has after 5 turns"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    for(int i=0 ; i<5 ; i++){
        game.playTurn();
    }

    CHECK(p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52 );
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
}

#5
TEST_CASE("Check if the game is over after 26 turns"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardsTaken() == 26);
    CHECK(p2.cardsTaken() ==26);   
}

#6
TEST_CASE("Check if there is a winner at the end of the game"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();

    if(game.p1.stacksize() == 0){
        CHECK(game.p2.stacksize() == 52);
    }else{
        CHECK(game.p1.stacksize() == 52);
        CHECK(game.p2.stacksize() == 0);
    }
}