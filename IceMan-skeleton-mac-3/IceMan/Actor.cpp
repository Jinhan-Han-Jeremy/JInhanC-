#include "Actor.h"
#include "StudentWorld.h"
/*
 MAN IMPLEMENTATION
 */
void IceMan::doSomething()
{
    if (getWorld()->getLives() <= 0)
    {
    }
    else
    {
        int ch = getWorld()->getcurrentKey();
        if (getWorld()->getKey(ch) == true)
        {
            switch(ch)
            {
                case KEY_PRESS_LEFT:
                    if(getWorld()->radiusCalculator(getX(), getY(), getWorld()->BoulderX()+2,getWorld()->BoulderY()+2, 3)|| getX()<1)  // BoulderX()+2 BoulderY()+2 is the center of boulder
                        setDirection(left);
                    else if(getX()>0 && !getWorld()->radiusCalculator(getX(), getY(), getWorld()->BoulderX(),getWorld()->BoulderY(), 3))
                        {
                            setDirection(left);
                            moveTo(getX()-1, getY());
                        }
                    break;
                case KEY_PRESS_RIGHT:
                    if(getWorld()->radiusCalculator(getX(), getY(), getWorld()->BoulderX()+2,getWorld()->BoulderY()+2, 3)||getX()>59)   // BoulderX()+2 BoulderY()+2 is the center of boulder
                        setDirection(right);
                    else if(getX()<60)
                        {
                        setDirection(right);
                        moveTo(getX()+1, getY());
                        }
                    break;
                case KEY_PRESS_DOWN:
                    if(getWorld()->radiusCalculator(getX(), getY(), getWorld()->BoulderX(),getWorld()->BoulderY(), 3)||getY()<1)   // BoulderX()+2 BoulderY()+2 is the center of boulder
                        setDirection(down);
                    else if(getY()>0)
                    {
                        setDirection(down);
                        moveTo(getX(), getY()-1);
                    }
                    break;
                case KEY_PRESS_UP:
                    if(getWorld()->radiusCalculator(getX(), getY(), getWorld()->BoulderX(),getWorld()->BoulderY(), 3)||getY()>59)
                        setDirection(up);
                    else if(getY()<60)                     //  max = 64  pic = 4x4  so  64-4 == 60
                    {
                        setDirection(up);
                        moveTo(getX(), getY()+1);
                    }
                    break;
                case KEY_PRESS_SPACE:
                    if(getWorld()->getLeftSquirts() > 0)
                    {
                    getWorld()->playSound(SOUND_PLAYER_SQUIRT);
                    getWorld()->decreaseSquirts();
                    }
                    
                    break;
                case 'z' : case 'Z' :
                   if(getWorld()->getNumofSonar()>0)
                   {
                       if(getWorld()->getNumofSonar()>0)
                       {
                           getWorld()->playSound(SOUND_SONAR);
                           getWorld()-> finder();
                       getWorld()->decreaseSonar();
                       }
                   }
                    break;
                case KEY_PRESS_ESCAPE:
                    getWorld()->setcurrentKey('\x1b');
                    break;
                case KEY_PRESS_TAB:
                    if(getWorld()->getNumofGold()>0)
                    {
                        
                        getWorld()-> tempGold();
                        getWorld()-> decreaseGold();
                    }
                    break;
                    
            }
        }
    }
    
        if (reomoveIce())
        {
            getWorld()->playSound(SOUND_DIG);
        }
    --tick_man;
    if(tick_man==0)
        tick_man = 20;
}

// for boulder
void Boulder::doSomething()
{

/*
    while(tick_b > 0)
        tick_b--;
    tick_b = 30;
    while(IcelessLocation(getX(),getY()-1)==true)
    {
 
        getY() =-1;
        
    }
  */
   
}

bool IceMan::reomoveIce()
{
    return getWorld()->IceRemover(getX(), getY());
}


Protester::~Protester()
{
}

void Protester::doSomething()
{
    if (theProtesterHasZeroHitPoints())
        GameController::getInstance().playSound(SOUND_PROTESTER_GIVE_UP);
    
}

bool Protester:: theProtesterHasZeroHitPoints()
{
    if(getHealth()==0)
        return true;
    else
        return false;
        
}
void Protester::decHealth(int damage)
{
    if (health > 0)
    {
        health -= damage;
        
        if (health <= 0)
        {
            getWorld()->decLives();
        }
    }
}

int TempGoldNugget::getticks() { return tick_temp; }     //returns ticks


void TempGoldNugget::doSomething()
{
    if(getticks()==0)
    {setVisible(false);

    }
    else
    { tick_temp--;
        cout<< tick_temp<< endl;
        return;}
    
}

void PermGoldNugget::doSomething()
{
    if((getWorld()->radiusCalculator(getWorld()->Iceman_X(),getWorld()->Iceman_Y(), getX(), getY(), 4)&&stat==stable) || stat==wakeup)
    {
        setVisible(true);
        stat= wakeup;
       if(getWorld()->radiusCalculator(getWorld()->Iceman_X(),getWorld()->Iceman_Y(), getX(), getY(), 3)&&(stat==stable||stat==wakeup))
       {
           stat=sleep;
              setVisible(false);
           getWorld()->increaseGold();
           getWorld()->playSound(SOUND_GOT_GOODIE);
       }
        
    }
    else
    {setVisible(false);}
}

void Barrel::doSomething()
{
    if((getWorld()->radiusCalculator(getWorld()->Iceman_X(),getWorld()->Iceman_Y(), getX(), getY(), 4)&&stat==stable)||stat==wakeup)
    {
        setVisible(true);
        stat= wakeup;
        if(getWorld()->radiusCalculator(getWorld()->Iceman_X(),getWorld()->Iceman_Y(), getX(), getY(), 3)&&(stat==stable||stat==wakeup))
        {
            stat=sleep;
            setVisible(false);
        getWorld()->increaseOil();
        getWorld()->playSound(SOUND_GOT_GOODIE);
        }
        
    }
    else
    {setVisible(false);}
}


int Sonar::getticks() { return tick_so; }
void Sonar::doSomething()
{
    while(getticks()>0)
    { tick_so--;
        
        if(tick_so == 0)
            setVisible(false);
    }
    tick_so = getWorld()->numOfSonarAndWaterTicks();
}

void Squirt::doSomething()
{
}

void WaterPool::doSomething()
{
    cout << ticks << endl;
    
    while(ticks>0)
    { ticks--;
        
        if(ticks == 0)
            setVisible(false);
        cout <<"dd"<< ticks << endl;
    }
    ticks = getWorld()->numOfSonarAndWaterTicks();
}

int WaterPool::getticks()
{ return ticks; }


void HardcoreProtester::doSomething()
{
}



