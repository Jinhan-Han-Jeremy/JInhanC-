//
//  main.cpp
//  cs30_list5.5.2018
//
//  Created by Jinhan Han on 5/2/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//
/*#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include<mutex>
#include<new>
#include<exception>
using namespace std;
struct List
{
    struct Node
    {
        int value;
        Node* next;
        Node(int y) : value(y), next(nullptr){}
    };
    Node *head;
    List():head(nullptr){}
    std::mutex m;
    //m.lock();
    void insert(int value)
    {
        std:: unique_lock<std:: mutex> l{m}; //for throw
        auto node = new Node(value);
        throw std::bad_alloc();
        node-> next = head;
        head = node;
    //m.unlock();
    }
    int count() const
    {
        int count = 0;
        auto p =head;
        while(p!= nullptr)
        {
            count ++;
        }
    };
};

void thefun(List list)
{
    for(int i = 0 ; i< 100 ; i++)
    {
        try{
    list.insert(i);
        }
        catch(...)
        {
            cout << " no idea  " << endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    List l;
    
    // insert code here...
    std::vector<std::thread> workers;
    
    for(int i =0; i < 10; i++)
    {
        
        workers.push_back(std:: thread (thefun, std::ref(1)));
    }
    std::for_each(std:: begin(workers), std::end(workers), [](std::thread))
    th.join();});
    return 0;
}*/



#include <iostream>
#include <thread>
#include <list>
#include <future>
#include<new>
using namespace std;

void thefunc()
{}

int main()
{
    promise<int> prms;
    future<int> fut = prms.get_future();
    thread th (thefunc,3,result);
    
    
}
