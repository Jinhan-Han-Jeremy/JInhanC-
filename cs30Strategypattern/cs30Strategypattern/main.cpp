//
//  main.cpp
//  cs30Strategypattern
//
//  Created by Jinhan Han on 4/18/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//


#include <iostream>

using namespace std;

class KickBehavior
{
public:
    virtual void kick() = 0;
};

// Encapsulated kick behaviors
class LightningKick : public KickBehavior
{
public:
    void kick()
    {
        cout <<"Lightning Kick " <<endl;
    }
};
class TornadoKick  : public KickBehavior
{
public:
    void kick()
    {
        cout <<"Tornado Kick " <<endl;
    }
};


class JumpBehavior
{
public:
   virtual void jump() = 0;
};

// Encapsulated jump behaviors
class ShortJump  : public JumpBehavior
{
public:
    void jump()
    {
        cout <<"Short Jump " <<endl;
    }
};

class LongJump : public JumpBehavior
{
public:
    void jump()
    {
        cout <<"Long Jump " <<endl;
    }
};

class Fighter
{
   
public:
    KickBehavior *kickBehavior;
    JumpBehavior *jumpBehavior;
    
     void punch()
    {
        cout <<" Punch " <<endl;
    }
    void kick()
    {
        // delegate to kick behavior
        kickBehavior->kick();
    }
    void jump()
    {
        // delegate to jump behavior
        jumpBehavior->jump();
    }
    void roll()
    {
        cout <<"Default Roll " <<endl;
    }
    void setKickBehavior(KickBehavior kickBehavior)
    {
        this->kickBehavior = &kickBehavior;
    }
    void setJumpBehavior(JumpBehavior jumpBehavior)
    {
        this->jumpBehavior = &jumpBehavior;
    }
    virtual void display() = 0;
};

// Characters
class Ryu : public Fighter
{
    public:
    Ryu()
    {
        
        jumpBehavior =  new ShortJump();
        kickBehavior = new TornadoKick();
    }
    void kick()
    {
        // delegate to kick behavior
       
    }
    void display()
    {
        cout <<"Ryu " <<endl;
    }
};

class Ken  : public Fighter
{
    public:
    Ken()
    {
        kickBehavior = new TornadoKick();
        jumpBehavior =  new LongJump();
    }
    void display()
    {
        cout <<"Ken " <<endl;
    }
};

class ChunLi  : public Fighter
{
    public:
    ChunLi()
    {
        kickBehavior = new LightningKick();   // adjustable
        jumpBehavior = new ShortJump();
    }
    void display()
    {
        cout <<"ChunLi " <<endl;
    }
};

// Driver class
    int main()
    {
        // Make a fighter with desired behaviors
        Fighter *ken = new Ken();
        Fighter *ryu = new Ryu();
        Fighter *chunli = new ChunLi();
        
        ken->display();
        
        // Test behaviors
        ken->punch();
        ken->kick();
        ken->jump();
        cout << "  ---------  next -----------     "<< endl;
        
        ryu->display();
        ryu->punch();
        ryu->kick();
        ryu->jump();
        
        cout << "  ---------  next -----------     "<< endl;
        
        chunli->display();
        chunli->punch();
        chunli->kick();
        chunli->jump();
        
        // Change behavior dynamically (algorithms are
        // interchangeable)

        
        return 0;
    }
