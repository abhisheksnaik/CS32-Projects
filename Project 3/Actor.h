#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor: public GraphObject
{
public:
    Actor(int imageID, double startX, double startY, int dir = 0, double size = 1.0, int depth = 0)
    :GraphObject(imageID, startX, startY, dir, size, depth)
    {
        m_isAlive = true;
    }
    void killMe()
    {
        m_isAlive = false;
    }
    bool isAlive()
    {
        return m_isAlive;
    }
    virtual void doSomething() = 0;
    
private:
    bool m_isAlive;
};


class Star: public Actor
{
public:
    Star(double startX, double startY)
    :Actor(IID_STAR, startX, startY, 0, randInt(50, 500)/1000.0, 3)
    {
    }
    virtual void doSomething();
private:
    
};


class NachenBlaster: public Actor
{
public:
    NachenBlaster(StudentWorld* world)
    :Actor(IID_NACHENBLASTER, 0, 128, 0, 1, 0)
    {
        m_health = 50;
        m_cabbage = 30;
        m_world = world;
    }
    bool isAlive();
    
    StudentWorld* getWorld();
    
    virtual void doSomething();
    
private:
    int m_health;
    int m_cabbage;
    StudentWorld* m_world;
};



#endif // ACTOR_H_
