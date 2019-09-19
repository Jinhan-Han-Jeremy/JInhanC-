//
//  StudentWorld.cpp
//  IceMan
//
//  Created by Jinhan Han on 5/19/18.
//  Copyright © 2018 CS32 Instructor. All rights reserved.
//
#include "StudentWorld.h"

using namespace std;

GameWorld* createStudentWorld(string assetDir)
{ return new StudentWorld(assetDir); }

int StudentWorld::init()
{
    currentKey = 0;
    Ice_man = new IceMan(this);
    Ice_man->setVisible(true);
  
    for (int i = 0; i < 64; i++)   //  for column
    {
        for (int j = 0; j < 64; j++)  // for row
        {
            if((i<30 || i >33 || j<4) && (j < 60)  )
            {
            ice_block[i][j] = new Ice(i, j, this);    // initilizing ice[][]
            // for row 30 31 32 33, for column 61,62,63,64 they don't show out ice
                
            }
            else
            ice_block[i][j] = nullptr;
        }
    }
    generatorObj(G,0);
    generatorObj(L,1);
    boulderGenerator();
    GoldNuget = 5;
    LeftSquirts=5;
    OilBarrels = 0;
    SonarKits = 10;
    
    return GWSTATUS_CONTINUE_GAME;
}


void StudentWorld:: boulderGenerator()
{
    int x= 0;
    int y= 0;
    int setRightfield = rand() % 2; // it decides the boulder is set on the right or left
    
    int k =0;
    
    while( k < numOfBoulders())
    {
        y = rand() % 56;  // Location (60 - 4)px set boulder in the ice field vertically
        x = rand()%26;  // Location (30 - 4)px set boulder in the ice field on the right horizontally
        
        if(setRightfield ==0) // set boulder on the right field after empty shaft
        {
            x= x + 33;
        }
        
        if((x<26 || (x >33 && x < 60)) && (y < 56) )
        {
            // for row 30 31 32 33, for column 61,62,63,64 they don't show out boulder
            IceRemover(x, y); //remove ice before locating boulder
            bool generator = false;
            
            if(k > 0)
            {
                for( int l =k-1; l < 0; l--)
              {
                if(radiusCalculator( actorr[l]->getX(), actorr[l]->getY(), x, y, 6) == true)
                    // if radius is less than 6
                 {
                     generator = true; // it is less than 6 radius
                 }
                 
              }
            }
            else if(k==0)
            {
                Boulder *b = new Boulder(x,y,this);
                actorr.push_back(b);
                boulderr.push_back(b);
                /*
                cout << "sona" << SonarPool <<endl;
                WaterPool *c = new WaterPool(SonarPool,4,4,this);
                
                c->doSomething();
                actorr.push_back(c);
                 */
                
                generator = true;
                k++;
            }
            
            if(!generator)
            {
               Boulder *b = new Boulder(x,y,this);
                actorr.push_back(b);
                boulderr.push_back(b);
                k++;
            }
        }
    }
  
}

void StudentWorld::generatorObj(int numberOf, int choice)
{
    int x= 0;
    int y= 0;
    int setRightfield = rand() % 2; // it decides the boulder is set on the right or left
    
    int k =0;
    while( k < numberOf)
    {
        y = rand() % 56;  // Location (60 - 4)px set boulder in the ice field vertically
        x = rand()%26;  // Location (30 - 4)px set boulder in the ice field on the right horizontally
        
        if(setRightfield ==0) // set boulder on the right field after empty shaft
        {
            x= x + 33;
        }
        
        if((x<26 || (x >33 && x < 60)) && (y < 56) )
        {
            // for row 30 31 32 33, for column 61,62,63,64 they don't show out obj
            
            bool generator = false;
            
            if(k > 0)
            {
                for( int l =k-1; l < 0; l--)
                {
                    if(radiusCalculator(actorr[l]->getX(), actorr[l]->getY(), x, y, 6) == true)
                        // if radius is less than 6
                    {
                        generator = true; // it is less than 6 radius
                    }
                    
                }
            }
            else if(k==0)
            {
                if(choice==0)// it is for gold
                {
                    PermGoldNugget *g = new PermGoldNugget(this, x,y);
                    actorr.push_back(g);
                /*
                 cout << "sona" << SonarPool <<endl;
                 WaterPool *c = new WaterPool(SonarPool,4,4,this);
                 
                 c->doSomething();
                 actorr.push_back(c);
                 */
                generator = true;
                }else if(choice==1)
                {
                    Barrel *oi = new Barrel(x,y,this);
                    actorr.push_back(oi);
                    /*
                     cout << "sona" << SonarPool <<endl;
                     WaterPool *c = new WaterPool(SonarPool,4,4,this);
                     
                     c->doSomething();
                     actorr.push_back(c);
                     */
                    generator = true;
                }
                k++;
            }
            
            if(!generator)
            {
                
                if(choice==0)// it is for gold
                {
                    PermGoldNugget *g = new PermGoldNugget(this,x,y);
                    actorr.push_back(g);
                }else if(choice==1)
                {
                    Barrel *oi = new Barrel(x,y,this);
                    actorr.push_back(oi);
                }
                k++;
                
            }
        }
    }
    
}
bool StudentWorld:: radiusCalculator(int x, int y , int objectX, int objectY, int radius)
{
    double horizontal = abs(objectX-x);
    double vertical = abs(objectY-y);
    double distance = sqrt(pow(horizontal,2)+ pow(vertical, 2));
    // If calculated distance is greater than radius, it returns false
    if(distance > radius )
    return false;  // out of radius
    else
    return true;  // within radius
}


int StudentWorld::move()
{
    setDisplayText();
    Ice_man->doSomething();
    
    vector<Actor *> tem;
    
        for(auto i= actorr.begin(); i != actorr.end(); i++)
    {
        (*i)->doSomething();
   
    }
    
    if (currentKey == KEY_PRESS_ESCAPE)
        {

        decLives();
        playSound(SOUND_PLAYER_GIVE_UP);
        return GWSTATUS_PLAYER_DIED;
        }
    
        if(numOfOilBarrels()==0)
        
        return GWSTATUS_FINISHED_LEVEL;
    
        return GWSTATUS_CONTINUE_GAME;
}

bool StudentWorld::IceRemover(int x, int y)
{
    bool dig = false;
    for (int i = x; i < x + 4; i++)
    {
        for (int j = y; j < y + 4; j++)
        {
            
            if (ice_block[i][j]!=nullptr)
            {
                dig = true;
                Ice * temp = ice_block[i][j];
                ice_block[i][j] = nullptr;
                delete temp;  // deleting dynamically allocated Ice
            }
        }
    }
    return dig;
}

bool StudentWorld::IcelessLocation(int x, int y)
{
    if(ice_block[x][y] == nullptr)
            return true;  // no ice location
    
    else
            return false;
}

void StudentWorld::tempGold()
{
    TempGoldNugget *tgold = new TempGoldNugget(100, Iceman_X(), Iceman_Y(), this);
    tgold->doSomething();
    tgold->setVisible(true);
}
void StudentWorld::finder()
{
    for(int i = 0; i< actorr.size(); i++ )
    {
        if(radiusCalculator(Iceman_X(), Iceman_X(), actorr[i]->getX(), actorr[i]->getY() , 12))
            actorr[i]->setState(Actor::wakeup);
        
    }
            
}

int StudentWorld::getNumofSonar()
{
    return SonarKits;
}

int StudentWorld::getNumofOil()
{
    return OilBarrels;
}

bool StudentWorld::isThereIce(int x, int y)
{
    return false;
}

 string StudentWorld::someFunctionYouUseToFormatThingsNicely(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score)
{
    return  "Lvl: " + to_string(level) + " " + "Lives: " + to_string(lives) + " " + "Hlth: " +
    to_string(health) + "% " + "Wtr: " + to_string(squirts) + " " + "Gld: "
    + to_string(gold) + " " + "Sonar: " + to_string(barrelsLeft) + " "  + "Oil Left: " + to_string(sonar)    + " "  + "Scr: " + to_string(score) + " "  ;
}

void StudentWorld::setDisplayText()
{
    score += getScore();
    string s = someFunctionYouUseToFormatThingsNicely(getLevel(), getLives(), Ice_man->getHealth() * 10, getLeftSquirts(), getNumofGold(), getNumofSonar(), getNumofOil(), score);
    
    GameWorld::setGameStatText(s);
}

int StudentWorld::getcurrentKey()
{ return currentKey; }
void StudentWorld::setcurrentKey(int k)
{
    currentKey = k ;
}

int StudentWorld::numOfGoldNuggetsINfield()
{ return G; }

int StudentWorld::numOfBoulders()
{ return B; }

int StudentWorld::numOfOilBarrels()
{ return L; }

int StudentWorld::numOfSonarAndWaterTicks()
{ return SonarPool; } //returns how many ticks until sonar kit disappears

int StudentWorld::numOfProtesterSpawn()
{ return P; }

bool StudentWorld::VisibleIce(int x, int y)
{ return ice_block[x][y]; }

void StudentWorld::cleanUp()
{
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            Ice* temp = ice_block[i][j];  //dynamic allocation
            ice_block[i][j] = nullptr;   // set nullptr to delete this one
            delete temp;
        }
    }
    
    vector<Actor *> tem;
    //delete
    for (int i = 0 ; i<actorr.size(); i++)
    {
        tem= actorr;
        actorr[i] = nullptr;
        delete tem[i];
    }
    //delete Iceman
    IceMan *tempman = Ice_man;
    Ice_man = nullptr;
    delete tempman;
}


void StudentWorld::increaseSquirts() {LeftSquirts += 5;}

int StudentWorld::getLeftSquirts()
{
    return LeftSquirts;
    
}
void StudentWorld::decreaseSquirts()
{
    LeftSquirts--;
}
void StudentWorld::decreaseSonar()
{
    SonarKits--;
}

void StudentWorld::increaseGold()
{
    ++OilBarrels;
    score+=10;
}

void StudentWorld::increaseOil()
{
    ++GoldNuget;
    score+=1000;
}

void StudentWorld::decreaseGold()
{
    --GoldNuget;
}





