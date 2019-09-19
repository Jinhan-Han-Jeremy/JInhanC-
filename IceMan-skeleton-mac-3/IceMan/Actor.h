//JinhanHan
//JinhanHan
#ifndef ACTOR_H_
#define ACTOR_H_
#include "GraphObject.h"
#include "GameController.h"
#include <algorithm>

using namespace std;

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* studenWorld) : GraphObject(imageID, startX, startY, dir, size, depth), world(studenWorld), alive(true) {};
    enum State { wakeup, stable, sleep };
    State stat=stable;
    void setState(State statt){stat = statt;};
    
    void decTick(int ttk){ttk--;};
    virtual void doSomething()
    {};
    StudentWorld* getWorld() const
    {
        return world;
    }
    
    void Ask_all_actors_to_do_something()
    {
        if (Alive()== true)
            doSomething();
        else
            return;
    }
  
    bool Alive() //checker object is alive or not
    { return alive; }
    
    virtual bool RegProtester()// for protester
    { return false; }
    
    virtual bool HCProtester()// for protester
    { return false; }
    
    void dead() // change alive to dead
    { alive = false; }
    
private:
    StudentWorld* world;
    bool alive;
};


class Character : public Actor {
public:
    Character(int id, int x, int y, Direction dir, double size, int dep, StudentWorld* studenWorld, int hp) :
    Actor(id, x, y, dir, size, dep, studenWorld), health(hp) {}
    int getHealth() const
    { return health; }
    
    virtual void decHealth(int damage)
    { health -= damage; }
protected:
    int health;
    
};


class IceMan : public Character {
public:
    IceMan(StudentWorld* studenWorld) : Character(IID_PLAYER, 30, 60, right, 1.0, 0, studenWorld, 10)
    {};
    void decHealth(int damage)
    { health -= damage; }
    
    virtual void doSomething();
private:
    bool reomoveIce();
    int tick_man=20;
};


class Protester : public Character {
protected:
   
    
    bool theProtesterHasZeroHitPoints();
    
    int waitCount;
    int tick_p = 20;
    
public:
    void decHealth(int damage);
    
   
    void doSomething();
    
    ~Protester();
private:
};
    
class HardcoreProtester : public Protester
{
public:
    HardcoreProtester(StudentWorld *studenWorld);
    void doSomething();
    
    virtual bool RegProtester()
    { return false; }
    
    virtual bool HCProtester()
    { return true; }
private:
    int tick_hp=20;
};

class Ice : public Actor {
public:
    Ice(int startX, int startY, StudentWorld* studenWorld) :
    Actor(IID_ICE, startX, startY, right, 0.25, 3, studenWorld)
    {
        setVisible(true);
    };
    virtual void doSomething() {};
    
};

class Goodies :public Actor {
public:
    Goodies(StudentWorld* studenWorld, const int img, int randomX, int randomY) :
    Actor(img, randomX, randomY, right, 1.0, 2, studenWorld) {};
   
    virtual void doSomething() {};
};

class Boulder : public Actor {
public:
    enum State { stable, falling };
    Boulder(int x, int y, StudentWorld* studenWorld) :
    Actor(IID_BOULDER, x, y, down, 1.0, 1, studenWorld), currentState(stable), tick_b(0){ setVisible(true);};
    
    void doSomething();
    
private:
    State currentState;
    int tick_b = 30;
};


class Barrel : public Goodies{
public:
    Barrel(int X, int Y, StudentWorld* studenWorld) :
    Goodies(studenWorld, IID_BARREL, X, Y){};
    
    void doSomething();
    int tick_bo = 20;
};


class Sonar : public Goodies {
public:
    Sonar(int tick_sso, int X, int Y, StudentWorld* studenWorld) :
    Goodies(studenWorld, IID_SONAR, X, Y) {
        tick_so = tick_sso;
    };
    virtual void doSomething();
    int getticks();
private:
    int tick_so;
};

class TempGoldNugget : public Goodies {
public:
    TempGoldNugget(int timeTicks, int X, int Y, StudentWorld* studenWorld) :
    Goodies(studenWorld, IID_GOLD, X, Y), tick_temp(timeTicks)
    {
      
    };

    int getticks();
    void setTick(){tick_temp--;};
    void doSomething();
private:
    int tick_temp;
};

class PermGoldNugget : public Goodies {
public:
    PermGoldNugget(StudentWorld* studenWorld, int randX, int randY) :
    Goodies(studenWorld, IID_GOLD, randX, randY) {};
    
    void doSomething();
private:
    bool found = false;
    int tick = 20;
};

class WaterPool : public Goodies {
public:
    WaterPool( int tickss, int randX, int randY, StudentWorld* studenWorld) :
    Goodies(studenWorld, IID_WATER_POOL, randX, randY)
    {
        ticks= tickss;
        setVisible(true); };
    
    int getticks();
    
    virtual void doSomething();
private:
    int ticks ;
    
};
       //returns how many ticks i have till this object dies

class Squirt : public Actor  {
public:
    Squirt(StudentWorld* studenWorld, Direction d, int x, int y) :
    Actor(IID_WATER_SPURT, x, y, d, 1, 2, studenWorld) { squirt_distance = 4; };

    virtual void doSomething();
private:
    int squirt_distance;
};

#endif // ACTOR_H_



