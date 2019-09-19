//
//  main.cpp
//  5mutext_test
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m;

void funcA()
{
    for (int i =0; i<4; i++)
        cout  << i;
}
void funcB()
{
    cout << endl;
    unique_lock<mutex> l(m);
    for (int i=3; i < 6; i++)
        cout << i;
}
void funcC()
{
    cout << endl;
    m.lock();
    for(int i =6; i<9; i++)
    {   cout << i;}
    m.unlock();
}
int main()
{
    thread th1(funcA);
    thread th2(funcA);
    th1.join();
    th2.join();
    
    thread th3(funcC);
    thread th4(funcC);
    th3.join();
    th4.join();
    thread th5(funcB);
    thread th6(funcB);
    th5.join();
    th6.join();
    thread th7(funcB);
    thread th8(funcB);
    th7.join();
    th8.join();
}
/*int main () {
thread th1(funcA);
thread th2(funcA);
th1.join();
th2.join();
}*/





/*
 #include <stdio.h>
 #include <list>
 #include <iostream>
 #include <vector>
 #include <mutex>
 #include <thread>
 #include <algorithm>
 using namespace std;
 
 struct List
{
    struct Node
    {
        int value;
        Node *next;
        Node (int v) : value(v), next(nullptr) {}
    };
 
 Node *head = nullptr;
 mutex m;
 
void insert(int value)
 {
 //m.lock();//2
     unique_lock<mutex> l(m);
 //l's constructor: m.lock() //3
     auto node = new Node(value);
     node->next = head;
     head = node;
 //m.unlock();//2
 //l's destructor: m.unlock() //3
 }
    //mutex m;//1
 int count()
 {
     //m.lock();//1
     int count=0;
     auto p = head;
     
     while(p!=nullptr)
     {
         count++;
         cout << p->value <<endl;
         p = p->next;
     }
 return count;
 
 }
 
};
 
 void thefun(List &list)
 {
 for (int i = 0; i<100; i++)
 list.insert(i);
 }
 
 int main()
 {
     
     List l;
     vector <thread> workers;
     
  
     
     
 for(int i = 0; i<10; i++)
     workers.push_back(thread (thefun, ref(l)));
 
   
 for_each(workers.begin(), workers.end(), [](thread &th){th.join();});
     cerr << "number of nodes " << l.count() <<endl;
 
 }*/

 


