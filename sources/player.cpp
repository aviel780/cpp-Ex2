#include<iostream>
#include <string>
#include"player.hpp"
using namespace std;

namespace ariel{
    

    Player::Player(std::string n){
        // this->name = n;
    }

    std::string Player::getName(){
        return "aviel";
    }
        // return this->name;
    

    int Player::stacksize(){
        return 1;
    }

    int Player::cardesTaken(){
        return 2;

    }
} // namespace arielbash