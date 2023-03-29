#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;


//1
TEST_CASE("Check players names"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);

    CHECK(game.pl1.name == "Alice");
    CHECK(game.pl2.name == "Bob");
}

//2
TEST_CASE("How many cardes each player has at the start of game"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);

    CHECK(pl1.stacksize() == 26);
    CHECK(pl2.stacksize() == 26);
    CHECK(pl1.cardesTaken() == 0);
    CHECK(pl2.cardesTaken() == 0);
}

//3
TEST_CASE("How many cardes each player has after 1 turn"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);

    game.playTurn();

    CHECK((pl1.stacksize() <= 25 || pl2.stacksize() <= 25));
    CHECK((pl2.cardesTaken() >= 1 || pl2.cardesTaken() >= 1));
}

//4
TEST_CASE("How many cardes each player has after 5 turns"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);

    for(int i=0 ; i<5 ; i++){
        game.playTurn();
    }

    CHECK(pl1.stacksize() + pl2.stacksize() + pl1.cardesTaken() + pl2.cardesTaken() == 52 );
    CHECK(pl1.stacksize() <= 21);
    CHECK(pl2.stacksize() <= 21);
}

//5
TEST_CASE("Check if the game is over after 26 turns"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);
    game.playAll();

    CHECK(pl1.stacksize() == 0);
    CHECK(pl2.stacksize() == 0);
    CHECK(pl1.cardesTaken() == 26);
    CHECK(pl2.cardesTaken() == 26);   
}

//6
TEST_CASE("Check if there is a winner at the end of the game"){
    Player pl1("Alice");
    Player pl2("Bob");

    Game game(pl1,pl2);
    game.playAll();

    if(game.pl1.stacksize() == 0){
        CHECK(game.pl2.stacksize() == 52);
    }else{
        CHECK(game.pl1.stacksize() == 52);
        CHECK(game.pl2.stacksize() == 0);
    }
}

//7
TEST_CASE("Check if there is any errors throwing"){
    Player pl1("Alice"); 
    Player pl2("Bob");

    Game game(pl1, pl2);

    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}