//
//  main.cpp
//  async
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

/*
#include <iostream>
#include <string>
#include <thread>
#include <future>
using namespace std;
string theFun()
{
    string str("Hello from future!");
    throw(logic_error("Exception from task!"));
    return (str);
}

int main ()
{
    future<string> ftr = async(theFun);
    cout << "Hello from main!\n";
    try
    {
        string str = ftr.get();
        cout << str;
    }
    catch(exception & e)
    {
        cout <<e.what()<< endl;
    }
}
*/


#include <iostream>

#include <future>

using namespace std;

double funcA(double a) {
    
    if(a<1)
        throw "less than 1";
    
    return a*a;
    
}

int funcB(int b){
    
    if(b<5)
        return b;
    
    return b*2;
    
}

int * funcC() {
    
    int * t = new int;
    
    return t;
    
}

int main() {
    
    // your code goes here
    
    int iValue, *iPtr;
    
    double dValue;
    
    cin>>iValue>>dValue;
    
    try {
        
        future<double> fut1 = async (funcA,3);
        
        dValue = fut1.get();
        
    } catch(char* s) {
        
        cout<<s<<endl;
        
    }
    
    cout<<dValue<<endl;
    cout << "ival " <<iValue <<endl;
    future<int> fut2 = async (funcB,iValue);
    
    iValue = fut2.get();
    
    try {
        
        future<int *> fut3 = async (funcC);
        
        iPtr = fut3.get();
        cout << "iptr" << *iPtr<<endl;
    } catch(const bad_alloc& e){
        
        cout<<"Allocation failed\n";
        
    }
    
    return 0;
    
}
