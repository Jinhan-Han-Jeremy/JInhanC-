//
//  main.cpp
//  binaryTree
//
//  Created by Jinhan Han on 3/3/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

//left is bigger number
//right is smaller number
#include <iostream>
using namespace std;

typedef int ItemType;

struct NNode {
    ItemType info;
    NNode* left;
    NNode* right;
};

class TreeType {
private:
    NNode* root;
    
    void Insert(NNode*& nodeptr, ItemType item);
    void deleter(NNode*& nodeptr, ItemType item);
    void Destroy(NNode*& nodeptr);
    void PrintTree(NNode* nodeptr);
public:
    TreeType() {root = nullptr;}
    ~TreeType();
    void deleted(ItemType item);
    void PutItem(ItemType item);
    void Print();
};

void TreeType::Print() {
    
    PrintTree(root);
    cout << endl;
}

void TreeType::PrintTree(NNode* nodeptr) {
    
    if (nodeptr == nullptr)
        return;
    
    
    PrintTree(nodeptr->right);
    cout << nodeptr->info << " ";
    PrintTree(nodeptr->left);
}

void TreeType::PutItem(ItemType item) {
    
    Insert(root, item);
}

void TreeType::Insert(NNode*& nodeptr, ItemType item) {
    
    if (nodeptr == nullptr) {
        nodeptr = new NNode;
        nodeptr->info = item;
        nodeptr->left = nullptr;
        nodeptr->right = nullptr;
        return;
    }
    if (item < nodeptr->info)
        Insert(nodeptr->right, item);
    else
        Insert(nodeptr->left, item);
}


void TreeType::Destroy(NNode*& nodeptr) {
    
    if (nodeptr != nullptr)
    {
        Destroy(nodeptr->left);
        Destroy(nodeptr->right);
        delete nodeptr;
    }
}

TreeType::~TreeType()
{
    Destroy(root);
}
void TreeType::deleter(NNode*& nodeptr, ItemType item)
{
    NNode *temp;
    if(nodeptr!=nullptr)
    {
        if (item < nodeptr->info)
            deleter(nodeptr->right, item);
        else if(item > nodeptr->info)
             deleter(nodeptr->left, item);
        else
        {
            temp=nodeptr;
            nodeptr=NULL;
            if (temp-> left< temp->right)
                nodeptr=temp->right;
            else
                nodeptr=temp->left;
        }
        
    }

}

void TreeType::deleted(ItemType item)
{
    deleter(root,item);
}

int main(int argc, const char * argv[])
{
    TreeType t;
    t.PutItem(5);
    t.PutItem(2);
    t.PutItem(3);
    t.PutItem(31);
    t.PutItem(1);
    
    t.deleted(3);
    t.Print();
    return 0;
}

