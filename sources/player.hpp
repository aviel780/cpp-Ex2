#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <stdio.h>

namespace ariel{



class Player{
    private:

        std::string name;
        // int stacksize;
        // int cardtaken;

    public:

        
        Player(std::string name);

        std::string getName();

        int stacksize();

        int cardesTaken();   

};
}
#endif //Player_hpp