//
//  main.cpp
//  maze
//
//  Created by Abhishek Naik on 2/14/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc)
    :m_r(rr), m_c(cc)
    {
    }
    int r() const
    {
        return m_r;
    }
    int c() const
    {
        return m_c;
    }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if(sc == ec && sr == er)
        return true;
    
    maze[sr][sc] = 'B';
    
    
    if(sr != nRows)
    {
        if(maze[sr+1][sc] == '.')
        {
            if(pathExists(maze, nRows, nCols, sr+1, sc, er, ec))
                return true;
        }
    }
    
    if(sc != nCols)
    {
        if(maze[sr][sc+1] == '.')
        {
            if(pathExists(maze, nRows, nCols, sr, sc+1, er, ec))
               return true;
        }
    }
    
    if(sr != 0)
    {
        if(maze[sr-1][sc] == '.')
        {
            if(pathExists(maze, nRows, nCols, sr-1, sc, er, ec))
                return true;
        }
    }
    
    if(sc != 0)
    {
        if(maze[sr][sc-1] == '.')
        {
            if(pathExists(maze, nRows, nCols, sr, sc-1, er, ec))
                return true;
        }
    }

    return false;
    
}


