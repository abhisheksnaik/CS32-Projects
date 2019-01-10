//
//  Game.hpp
//  cs32project1
//
//  Created by Abhishek Naik on 1/11/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

//#include <stdio.h>

class City;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();
    
    // Mutators
    void play();
    
private:
    City* m_city;
};



#endif /* Game_hpp */
