#include "StudentWorld.h"
#include "GameConstants.h"

#include <string>
#include <algorithm>
#include <list>

#include "Actor.h"
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetDir)
: GameWorld(assetDir)
{
}

int StudentWorld::init()
{
    m_blaster = new NachenBlaster(this);
    
    for(int i = 0; i < 30; i++)
    {
        Actor* star = new Star(randInt(0, VIEW_WIDTH-1), randInt(0, VIEW_HEIGHT-1));
        m_list.push_back(star);
        
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    list<Actor*>::iterator it;
    it = m_list.begin();
    
    while(it != m_list.end())
    {
        (*it)->doSomething();
        if(!((*it)->isAlive()))
        {
            delete *it;
            it = m_list.erase(it);
            continue;
        }
        it++;
    }
    
    m_blaster->doSomething();
    
    if(randInt(1, 15) == 7)
    {
        Actor* star = new Star(VIEW_WIDTH-1, randInt(0, VIEW_HEIGHT-1));
        m_list.push_back(star);
    }
    
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
    //return GWSTATUS_PLAYER_DIED;
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    list<Actor*>::iterator it;
    it = m_list.begin();
    
    while(it!=m_list.end())
    {
        delete *it;
        it = m_list.erase(it);
        
    }
    if(m_blaster != nullptr)
    {
        delete m_blaster;
        m_blaster = nullptr;
    }
    
}











