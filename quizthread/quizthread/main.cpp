//
//  main.cpp
//  quizthread
//
//  Created by Jinhan Han on 11/9/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <thread>
using namespace std;

void funcA()
{
    for(int i= 0; i<4; i++)
        cout << i;
}

void funcB()
{
    
}

int main()
{
    // insert code here...
    thread th1(funcA);
    //cout << " first ";
    thread th2(funcA);
    //cout << " second ";
    th1.join();
    //cout << " third ";
    th2.join();
}





/*
  first 0123 second 0123 third
  first 01230123 second  third
 0123 first 0123 second  third
 
 00112233
 
 */









