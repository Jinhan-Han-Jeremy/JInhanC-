//
//  map.hpp
//  cs30_project1
//
//  Created by Jinhan Han on 2/26/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

#pragma once
#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef std::string KeyType;
typedef double ValueType;

 // root pointer
class Map
{
private:
    struct Mapnode
    {
        Map* p;
        KeyType nodekeys;
        ValueType val;
        Mapnode *right, *left;
        // Constructor.  Make a node containing str.
        Mapnode(){};
        Mapnode(const Map& rhs) {};
        ~Mapnode(){};
        
    };
    //private data members
    
    Mapnode* root;
    
    //private functions
    const Map::Mapnode* copyHelper(const Mapnode* rhs);
    int theSize;
    
    Map::Mapnode* update_auxl(Mapnode *p, const KeyType& key) const; //Auxiliary function for update function
    void insert_auxl(Mapnode *&p, const KeyType & key, const ValueType & valu); //Auxiliary function for insert function
    Map::Mapnode* get_auxl(int& target, Mapnode* p, int curr_pos, KeyType& key, ValueType& valu) const;
    Map::Mapnode* erase_auxl(Mapnode *p, const KeyType& key);


public:
    Map();
    Map(const Map& rhs);
    ~Map();               // Create an empty map (i.e., one with no key/value pairs)
    
    Map& operator= (Map rhs) ; // operator function
    
    bool empty() const;    // Return true if the map is empty, otherwise false.
    
    int size() const;    // Return the number of key/value pairs in the map.
    
    bool insert(const KeyType& key, const ValueType& value);
    // If key is not equal to any key currently in the map, and if the
    // key/value pair can be added to the map, then do so and return true.
    // Otherwise, make no change to the map and return false (indicating
    // that either the key is already in the map).
    
    bool update(const KeyType& key, const ValueType& value);
    // If key is equal to a key currently in the map, then make that key no
    // longer map to the value it currently maps to, but instead map to
    // the value of the second parameter; return true in this case.
    // Otherwise, make no change to the map and return false.
    
    bool insertOrUpdate(const KeyType& key, const ValueType& value); // insert function
    
    bool erase(const KeyType& key);//erase selected one node
    
    bool contains(const KeyType& key) const;// it is checker whether the selected key is in tree
    
    bool get(const KeyType& key, ValueType& value) const;// get function converts selected pair's value to input value
    
    bool get(int i, KeyType& key, ValueType& value) const;// Another get function converts selected pair's value to input value
    void swap(Map& other);
   //swap two map
 
    void destroy_tre(Mapnode*& nodeptr); //destroy function for destroytree and destructor
    void dump() const; // print function

    void inorder_print(Mapnode *leaf)const;
    
   
};

void subtract(const Map& m1, const Map& m2, Map& result);

bool combine(const Map& m1, const Map& m2, Map& result);

#endif /* map_hpp */
