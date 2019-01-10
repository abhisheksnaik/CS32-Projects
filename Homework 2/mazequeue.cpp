//
//  main.cpp
//  queue
//
//  Created by Abhishek Naik on 2/6/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
{
    queue<Coord> coordQueue;
    Coord start(sr, sc);
    coordQueue.push(start);
    maze[sr][sc] = 'C'; //c for crumb
    
    while(!coordQueue.empty())
    {
        Coord front = coordQueue.front();
        coordQueue.pop();
        int r = front.r();
        int c = front.c();
        if(r == er && c == ec)
            return true;
        if(maze[r][c+1] == '.')
        {
            Coord east(r, c+1);
            coordQueue.push(east);
            maze[r][c+1] = 'B';
        }
        if(maze[r+1][c] == '.')
        {
            Coord south(r+1, c);
            coordQueue.push(south);
            maze[r+1][c] = 'B';
        }
        if(maze[r][c-1] == '.')
        {
            Coord west(r, c-1);
            coordQueue.push(west);
            maze[r][c-1] = 'B';
        }
        if(maze[r-1][c] == '.')
        {
            Coord north(r-1, c);
            coordQueue.push(north);
            maze[r-1][c] = 'B';
        }
    }
    return false;
}


/*
int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X...X..X.X",
        "X..XX....X",
        "X.X.XXXX.X",
        "XXX......X",
        "X...X.XX.X",
        "X.X.X..X.X",
        "X.XXXX.X.X",
        "X..X...X.X",
        "XXXXXXXXXX"
    };

    
    if (pathExists(maze, 10,10, 4,3, 1,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
 */
