//
//  main.cpp
//  test4_mid
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//
#include <iostream>
#include <list>
using namespace std;

struct Node{
    int info;
    Node *link;
};

class oneOwnerIntList
{
public:
    oneOwnerIntList(int item, size_t num);
    oneOwnerIntList(const oneOwnerIntList& rhs)= delete;
    const oneOwnerIntList& operator= (const oneOwnerIntList & rhs) = delete;
    
    oneOwnerIntList(oneOwnerIntList&& rhs)
    {
        head = rhs.head;
        rhs.head = nullptr;
    }
    oneOwnerIntList& operator= (oneOwnerIntList & rhs)
    {
        DestroyList();
        head= rhs.head;
        head=nullptr;
        return *this;
    }
    
    void DestroyList();
private:
    Node *head = nullptr;
};

void foo(oneOwnerIntList l);
int main()
{
    oneOwnerIntList l1 = {3,4,5,6}; // constructor
    oneOwnerIntList l2;
    foo( oneOwnerIntList(3, 13));
}
