#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"


using namespace ariel;

TEST_CASE("initial games"){
    Player p1("bob");
    Player p2("alice");
    Game game1(p1,p2);
    Player p3("aviel");
    Player p4("lee");
    Game game2(p3,p4);
    Player p5("eythn");
    Player p6("sharon");
    Game game3(p5,p6);
    Player p7("mosh");
    Player p8("gabi");
    Game game4(p7,p8);

    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p3.stacksize()==26);
    CHECK(p4.stacksize()==26);
    CHECK(p5.stacksize()==26);
    CHECK(p6.stacksize()==26);
    CHECK(p7.stacksize()==26);
    CHECK(p8.stacksize()==26);

    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
    CHECK(p3.cardesTaken()==0);
    CHECK(p4.cardesTaken()==0);
    CHECK(p5.cardesTaken()==0);
    CHECK(p6.cardesTaken()==0);
    CHECK(p7.cardesTaken()==0);
    CHECK(p8.cardesTaken()==0);
}

TEST_CASE("game with steps"){
    Player p1("bob");
    Player p2("alice");
    Game game1(p1,p2);
    CHECK_THROWS(game1.printWiner());// ther is non
    CHECK_THROWS(game1.printLastTurn());//ther is non
    CHECK_THROWS(game1.printLog());

    game1.playTurn();
    CHECK(p1.stacksize()!=p2.stacksize()); // some one have to take more cardes then the another

    CHECK_THROWS(game1.printWiner());//still not any win

    // the and game
    game1.playAll();//play all thw steps
    CHECK(p1.stacksize()!=p2.stacksize());

    CHECK_THROWS(game1.printWiner());//shoud to be good anless we have duce
    CHECK_THROWS(game1.printLastTurn());//shoud to be good 
    CHECK_THROWS(game1.printLog());//shoud to be good

}
  


TEST_CASE("an posibale sucoison"){
    Player p3("aviel");
    Player p4("lee");
    Player p5("eythn");
    Game game1(p3,p4);
    Game game2(p3, p5);
    CHECK(p3.stacksize()==26);
    game1.playTurn();
    CHECK(p3.stacksize()!=p4.stacksize());
    

// non of the funcsion shoud to be working becuse this is impsibale to play 2 games in the same time
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
    
    
}

