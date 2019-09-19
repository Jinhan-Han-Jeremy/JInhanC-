//
//  main.cpp
//  test2ivalue
//
//  Created by Jinhan Han on 11/9/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <string>
#include <new>
#include <future>
using namespace std;

double funcA(double a)
{
    if(a<1)
    throw "less Than 1";
    
    return a*a;
}
int funcB(int b)
{
    if(b<5)
        return b;
    
    return b * 2;
}
int * funcC()
{
    int * t = new int;
    
    return t;
}


int main() {
    
    // your code goes here
    
    int iValue, *iPtr;
    
    double dValue;
    
    cin>>iValue>>dValue;
    
    try {
        future<double> fut1 = async (funcA,dValue);
        
        dValue = fut1.get();
        
    } catch(char* s) {
        
        cout<<s<<endl;
        
    }
    
    cout<<dValue<<endl;
    
    future<int> fut2 = async (funcB,iValue);
    
    iValue = fut2.get();
    
    try {
        
        future<int *> fut3 = async (funcC);
        
        iPtr = fut3.get();
        
    } catch(const bad_alloc& e){
        
        cout<<"Allocation failed\n";
        
    }
    
    return 0;
    //out put 9 when it is 3 dvalue
}

/*int main() {
        int iValue, *iPtr;
        double dValue;
    
        cin >> iValue >> dValue;
        try {
            dValue = funcA(3);
        }
        catch (char *s) {
            cout << s << endl;
        }
    
    future <int*> ftrC = async(funcC);
    cout << dValue << endl;
        iValue = funcB(iValue);
    cout << iValue ;
        try {
            iPtr = ftrC.get();
        }
        catch (const bad_alloc& e) {
            cout << "Allocation failed\n";
        }
        return 0;
}*/
    /*
    // insert code here...
    int iValue, *iptr;
    double dValue;
    cout << "enter";
    cin >> iValue >> dValue;
    try{
        dValue =funcA(3);
        cout << "first it "<< " 1 "<< endl;
        }
    catch(char *s)
    {
        cout << "done";
        cout << s << endl;
    }
    cout << " second " << dValue << endl;
    iValue = funcB(iValue);
    try{
        iptr = funcC() ;
        cout << " 2 " ;
        }
    catch(const bad_alloc & e)
    {
        cout << " end ";
    }
    //
    //
    //
    return0;
}
*/
    
/*
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

