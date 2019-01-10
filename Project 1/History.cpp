//
//  History.cpp
//  cs32project1
//
//  Created by Abhishek Naik on 1/15/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include "History.h"
#include "City.h"
#include<iostream>
using namespace std;

History::History(int nRows, int nCols)
:m_nLocations(0)
{
    for(int i=1; i<=nRows; i++){
        for(int j=1; j<=nCols; j++){
            m_locations[m_nLocations] = new Location(i,j);
            m_nLocations++;
        }
    }
    cityRow = nRows;
    cityCol = nCols;
}

bool History::record(int r, int c){
    if (((r<1 || r>cityRow) || (c<1 || c>cityCol)))
        return false;
    for(int i = 0; i < m_nLocations; i++){
        if((m_locations[i]->row() == r) && (m_locations[i]->col() == c))
            m_locations[i]->increment();
    }
    return true;
}

void History::display() const{
    clearScreen();
    for(int i = 0; i< m_nLocations; i++){
        switch(m_locations[i]->getCount()){
            case 0:
                cout<<".";
                break;
            case 1:
                cout<<"A";
                break;
            case 2:
                cout<<"B";
                break;
            case 3:
                cout<<"C";
                break;
            case 4:
                cout<<"D";
                break;
            case 5:
                cout<<"E";
                break;
            case 6:
                cout<<"F";
                break;
            case 7:
                cout<<"G";
                break;
            case 8:
                cout<<"H";
                break;
            case 9:
                cout<<"I";
                break;
            case 10:
                cout<<"J";
                break;
            case 11:
                cout<<"K";
                break;
            case 12:
                cout<<"L";
                break;
            case 13:
                cout<<"M";
                break;
            case 14:
                cout<<"N";
                break;
            case 15:
                cout<<"O";
                break;
            case 16:
                cout<<"P";
                break;
            case 17:
                cout<<"Q";
                break;
            case 18:
                cout<<"R";
                break;
            case 19:
                cout<<"S";
                break;
            case 20:
                cout<<"T";
                break;
            case 21:
                cout<<"U";
                break;
            case 22:
                cout<<"V";
                break;
            case 23:
                cout<<"W";
                break;
            case 24:
                cout<<"X";
                break;
            case 25:
                cout<<"Y";
                break;
            default:
                cout<<"Z";
                break;
        }
        if(((i+1)%cityCol)==0)
            cout<<"\n";
    }
    cout<<"\n";
}

History::~History(){
    for(int i = 0; i <m_nLocations; i++)
        delete m_locations[i];
}

Location::Location(int r, int c)
{
    m_row = r;
    m_col = c;
    count = 0;
}

int Location::row(){
    return m_row;
}
int Location::col(){
    return m_col;
}

void Location::increment(){
    count++;
}

int Location::getCount(){
    return count;
}







