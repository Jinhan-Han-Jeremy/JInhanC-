//
//  main.cpp
//  listt
//
//  Created by Jinhan Han on 11/2/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//



#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
using namespace std;

struct List{
    struct Node{
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
       // m.lock();//1
        int count=0;
        auto p = head;
        while(p!=nullptr)
        {
            count++;
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
    
    
    for_each(workers.begin(), workers.end(),[](thread &th)
             {
                 th.join();
             });
    cout << "number of nodes" << l.count() <<endl;
}



