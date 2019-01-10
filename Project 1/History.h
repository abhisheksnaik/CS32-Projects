//
//  History.hpp
//  cs32project1
//
//  Created by Abhishek Naik on 1/15/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#ifndef History_hpp
#define History_hpp

//#include <stdio.h>
#include "globals.h"

class Location;
//class Grid;

/*class Grid
{
    Location* m_locations[MAXPOINT];
    int gridRow;
    int gridCol;
};
*/

class History
{
public:
    History(int nRows, int nCols);
    ~History();
    bool record(int r, int c);
    void display() const;
    
private:
    Location* m_locations[MAXPOINT];
    int m_nLocations;
    int cityRow;
    int cityCol;
};


class Location
{
public:
    Location(int nRows,int nCols);
    int row();
    int col();
    void increment();
    int getCount();
    
private:
    int m_row;
    int m_col;
    int count;
};

#endif /* History_hpp */
