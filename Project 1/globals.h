//
//  utilities.hpp
//  cs32project1
//
//  Created by Abhishek Naik on 1/11/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#ifndef globals_hpp
#define globals_hpp

//#include <stdio.h>
const int MAXROWS = 20;               // max number of rows in a city
const int MAXCOLS = 30;               // max number of columns in a city
const int MAXFLATULANS = 100;         // max number of Flatulans allowed
const int INITIAL_PLAYER_HEALTH = 10;
const int MAXPOINT = 20 * 30;

const int UP      = 0;
const int DOWN    = 1;
const int LEFT    = 2;
const int RIGHT   = 3;
const int NUMDIRS = 4;

int randInt(int min, int max);
void clearScreen();


#endif /* globals_hpp */
