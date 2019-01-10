#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
void NachenBlaster::doSomething()
{
    if(isAlive())
    {
        int ch;
        if(m_world->getKey(ch))
        {
            switch (ch) {
                case KEY_PRESS_UP:
                    if(getY()+6<VIEW_HEIGHT)
                        moveTo(getX(), getY()+6);
                    break;
                case KEY_PRESS_DOWN:
                    if(getY()-6>0)
                        moveTo(getX(), getY()-6);
                    break;
                case KEY_PRESS_LEFT:
                    if(getX()-6>0)
                        moveTo(getX()-6, getY());
                    break;
                case KEY_PRESS_RIGHT:
                    if(getX()+6<VIEW_WIDTH)
                        moveTo(getX()+6, getY());
                    break;
                default:
                    break;
            }
        }
    }
    else
        return;
}

void Star::doSomething()
{
    moveTo(getX()-1, getY());
    if(getX() == 0)
        killMe();
}

StudentWorld* NachenBlaster::getWorld()
{
    return m_world;
}

bool NachenBlaster:: isAlive()
{
    return m_health>0;
}

