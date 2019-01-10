//
//  utilities.cpp
//  cs32project1
//
//  Created by Abhishek Naik on 1/11/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//
#include <random>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "globals.h"

using namespace std;

int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}

void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}
