//
//  StudentWorld.h
//  IceMan
//
//  Created by Jinhan Han on 5/19/18.
//  Copyright © 2018 CS32 Instructor. All rights reserved.
//
#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "GraphObject.h"
#include "Actor.h"
#include <string>
#include<memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir)
    : GameWorld(assetDir)
    {
    }

    void setcurrentKey(int k);
    int getcurrentKey();
    bool IceRemover(int x, int y);
    void setDisplayText();
    
    int getNumofOil();
    int getNumofGold() {return GoldNuget;};
    int numOfBoulders(); // for boulder
    int numOfGoldNuggetsINfield();
    int getNumofSonar();
    int numOfOilBarrels();
    int numOfSonarAndWaterTicks();
    int numOfProtesterSpawn();
    void tempGold();
    bool VisibleIce(int x, int y);
    
    int Iceman_X() { return Ice_man->getX(); }
    int Iceman_Y() { return Ice_man->getY(); }
    int BoulderX() { return boulderr[0]->getX(); }
    int BoulderY() { return boulderr[0]->getY(); }
    
    
    void generateField(string type); // for protester
    int randXGenerator(string type); // for object
    int randYGenerator(string type); // for boulder
    bool isThereIce(int x, int y);
    
    void finder();
    void decreaseSonar();
    int getLeftSquirts();
    void decreaseSquirts();
    void decreaseGold();
    void increaseSquirts();
    void boulderGenerator();
    void increaseGold();
    void increaseOil();
    string someFunctionYouUseToFormatThingsNicely(int level, int lives, int health, int squirts, int gold, int barrelsLeft,int sonar,int score);
    
    bool shoutting(int x, int y);//for protester
    
    
    bool ProtestMoveOrNot(int x, int y); // for protester
    
    void SquirtWeapon(GraphObject::Direction dir, int x, int y);
    void killingProtester(int x, int y);  // for protester
    void deadIceMan()
    {
        Ice_man->decHealth(10);
    }
    void generatorObj(int numberOf, int choice);
    bool IcelessLocation(int x, int y);  //To check there is ice or not in the path
    bool radiusCalculator(int x, int y , int objectX, int objectY, int radius);
    virtual int init(); // initial
    virtual int move();
    virtual void cleanUp();
    
private:
    int SonarKits;
    int GoldNuget;
    int score= 0;
    int LeftSquirts;
    int OilBarrels;
    int current_level_number = getLevel();
    int G = max(5-current_level_number / 2, 2); // num of gold in field
    int B =min((int)(getLevel()/ 2 + 2), 9); //num of boulder in field
    int L = min(2 + current_level_number, 21); // num of oil in field
    int P = min(15, (int)(2 + current_level_number * 1.5)); //num of protester in field
    int T = max(25, 200 - current_level_number); // ticks for protester in field
    int probabilityOfHardcore = min(90, current_level_number * 10 + 30);// probabilityOfHardcore in field
    int SonarPool = max(100, 300 - 10 * current_level_number); //num of ticks for sonar and water pool in field
    int NumOfProtesters;
    int ProtesterTicksPassed = 0;
    int currentKey;
    int tickt=20;
    vector<Actor *> actorr;
    Actor* act;
    
    IceMan* Ice_man;
    vector<Boulder *> boulderr;
    Ice* ice_block[64][64];
    Protester* p;
   
};


#endif // STUDENTWORLD_H_




