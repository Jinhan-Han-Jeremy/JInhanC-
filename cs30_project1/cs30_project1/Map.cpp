//
//  map.cpp
//  cs30_project1
//
//  Created by Jinhan Han on 2/26/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

#include "Map.hpp"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

//Every constructor must be at the top location to use main information in function
//private data members
Map::Map()
{
}// Create an empty map (i.e., one with no key/value pairs)

Map::Map(const Map &rhs)
{
    if(root == nullptr)
        root = nullptr;
    else
        root = new Mapnode;
}

Map::~Map()
{
    destroy_tre(root); // destroy_tre(root) is delete root ptr.
}

Map::Mapnode* Map::update_auxl(Mapnode *p, const KeyType& key) const //Auxiliary function for update function
{
    
    if(p != nullptr)
    {
        if(p->nodekeys==key) //Check whether the key is the same or not
        {
          //cerr<< " matching key " << endl;
            return p;
        }
        //If p->node keys == key, p != nullptr
        
        else if(key > p->nodekeys)  // left node > right
        {
            p=update_auxl(p->left,key);
        }
        else if(key < p->nodekeys) // left node < right
        {
            p=update_auxl(p->right,key);
        }
    }
    
    return p;    //If p->node keys != key, p = nullptr.
}

void Map::insert_auxl(Mapnode *&p, const KeyType & key, const ValueType& valu) //Auxiliary function for insert function
{
    Mapnode*temp;
    if(p==nullptr)
    {
        temp = new Mapnode;     //dynamic allocation
        temp -> nodekeys = key;
        temp -> val = valu;
        temp -> right = nullptr;
        temp -> left = nullptr;
        p=temp;
    }
    else if(p!=nullptr)
    {
    if(key < p -> nodekeys) // step from p to p-> right or p-> left
        insert_auxl(p->right, key, valu);
    else
        insert_auxl(p->left, key, valu);
    }
}

Map::Mapnode* Map::erase_auxl(Mapnode *p, const KeyType& key) //return the node ptr that erased one node data
{
    Mapnode* temp;
   if(p == nullptr)
       return p;
    
   else if (p != nullptr)
    p = update_auxl(p,key);
    temp=p;
    //If p->node keys != key, p = nullptr.
    
    if (temp != nullptr)
    {
       
       p = NULL ;  // The current node data = null.
    
        
            p =temp->right;  //connect previous p to next root p
            erase_auxl(p,key);
        
    
           p =temp->left;  //connect previous p to next root p
            erase_auxl(p,key);
        
    }
        return temp;
}

const Map:: Mapnode* Map::copyHelper(const Mapnode* rhs)
{
    if(rhs == nullptr)
        return nullptr; // If there's no Node to copy, return NULL.
    
    Mapnode *temp;
    KeyType nullkey=NULL;
    
    if(rhs->nodekeys == nullkey)
    {
        cerr << "There is no keys" <<endl;
        return nullptr;
    }
    else
    {
        temp = new Mapnode ;  // Dynamically allocated memory
        temp->nodekeys = rhs->nodekeys;
        temp->val = rhs->val;
    }
    copyHelper(rhs->right); // Recursive call to left node.
    copyHelper(rhs->left); // Recursive call to right node.
    return temp; // Returns after child nodes have been linked to newNode.
}


int Map::size() const    // Return the number of key/value pairs in the map.
{
    return theSize;
}

//public
Map& Map::operator= (Map rhs)  // operator function
{
    rhs.swap(*this);    //swap rhs and current map class
    return *this;
}

bool Map::empty() const    // Return true if the map is empty, otherwise false.
{
    if (root == nullptr) //if rppt == nullptr , retur true
        return true;
    else
        return false;
}


bool Map::insert(const KeyType& key, const ValueType& value)
{
    // If p->node keys != key, p = nullptr.
    if(update_auxl(root,key) != nullptr)
    {
        return false;
    }
    else
    {
        insert_auxl(root, key, value);
        theSize=theSize+1; // increment of size of root after inserting datas to node.
        return true;
    }
}

bool Map::update(const KeyType& key, const ValueType& value)
{
    Mapnode* temp;
    temp=root;
    temp = update_auxl(temp,key); // Found node is assigned in temp. Without found node, temp = nullptr
    
    // If temp->node keys != key, p = nullptr.
    if(temp !=nullptr)
    {
        if(temp -> val == value) // unless it update data, return false
            return false;
        else
        {
            temp -> val = value;
            root=temp;              // dynamic allocation for root, root gets changed value
            return true;
        }
    }
    return false;
    
}
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) // insert function
{
    
    Mapnode* temp;
    
    // If p->node keys != key, p = nullptr.
    temp=update_auxl(root,key);
    if(temp!=nullptr)
    {
        update(key,value); // call update function to change value of tha pair
        return true;
    }
    else
    insert(key, value); // If input key is not the same with any keys in node, insert the pair into this map.
    
    return false;
}
bool Map::erase(const KeyType& key)//erase selected one node
{
    Mapnode* temp;
    temp = root;
    //If all root->nodekeys != key, erase_auxl(temp, key)=nullptr
    if(erase_auxl(temp, key)==nullptr)
        return false;
    else{
        --theSize;  //decrement of size of root after erasing one node
        return true;
        }
}
bool Map::contains(const KeyType& key) const// it is checker whether the selected key is in tree
{
     //If root->node keys != key, root = nullptr.
    Mapnode *p= update_auxl(root, key);
    
    if(p !=nullptr)
        return true;
    else
        return false;
}

Map::Mapnode* Map::get_auxl(int& target, Mapnode* p, int curr_pos, KeyType& key, ValueType& valu) const
{
    
    if(p!=nullptr)
    {
        
    if(curr_pos == target) // If current position == target position, key and value get new datas from Map.
    {
        
        //cerr<< " matching " << endl;
        key=p->nodekeys;   // assign node's key/val in parameter key/val
        valu=p->val;
        ++curr_pos;  ///after thata, the pos is increased

        return p;
    }
        ++curr_pos;
    }
    else        //if p == nullptr, return p
        return p;
    
    get_auxl(target,p->right, curr_pos, key, valu);
     ++curr_pos; // ++ currrent position before passing the root->left
    get_auxl(target,p->left, curr_pos, key, valu);
    
    return p;
}

bool Map::get(const KeyType& key, ValueType& value) const// get function converts selected pair's value to input value
{
    Mapnode* temp ;
    temp = update_auxl(root,key);
    
    //If root->nodekeys != input keys, temp = nullptr.
        if(temp == nullptr)
        return false;

    if(value != temp->val) // check value is same or not
    {value = temp->val;//assign value of map node into this value
        return true;}
    else
        return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const// Another get function converts selected pair's value to input value
{
    Mapnode* temp;
    temp = root;
    KeyType tem=" ";
    ValueType vo=0;
    
    if(size()-1 < i )  // If size of node < input i or temp!=nullptr, return false
        return false;
    
    temp=get_auxl(i,temp,0,tem,vo); //assign the node in temp.  The node is in i th order.
    
    //cerr<< "  what is tem : "<<tem <<"   " << key <<endl;
    
    
    if(tem==key)  //If tem keys == input keys,
    {
        if(value == vo) // check value is same or not
        {value=vo;
           // cerr<< "  what is key : "<< key<< endl;
            return false;}
        else
        {
            value=vo;
         //   cerr<< "  what is key : "<< key<< endl;
            return true;
        }
    }
    else if(tem!= key)
    {
        key=tem;
        value = vo;
       // cerr<< "  what is key : "<< key<< endl;
    }
    
    return true;
}
void Map::swap(Map& other)
{
    int size =theSize;
    Mapnode* temp ;
    
    temp = other.root;   //it assigns object root to pointer temp
    other.root = root; //it assigns root ptr to object root
    
    theSize= other.theSize;  // size is also swpped
    other.theSize=size;
    
    root= temp;  //it assigns pointer temp to root
}
//swap two map

void Map::inorder_print(Mapnode  *leaf) const
{
    if (leaf == nullptr)
        return;
    else{
        inorder_print(leaf->right);
        if(leaf->nodekeys!=" " || leaf->val != 0)  //to prevent null values
        {
        cerr <<" \nKey: "<< leaf->nodekeys << ", val: ";
        cerr << leaf->val << "  ";
        }
        inorder_print(leaf->left); //pointer leaf points right, repeat the function as a recursive function
    }
}
void Map::dump() const // print function
{inorder_print(root);}

void Map::destroy_tre(Mapnode*& nodep)//destroy function for destroytree and destructor
{
    if(nodep!=nullptr)
    {
        destroy_tre(nodep->right);//go right
        destroy_tre(nodep->left);//go left
        
        delete nodep;
        
    }
    else
        nodep=nullptr;
}

void test()
{
    Map m, m1, m2, m3,result;
    
    /*Map gpas;
    gpas.insert("Fred", 2.956);
    assert(!gpas.contains(""));
    gpas.insert("Ethel", 3.538);
    gpas.insert("", 4.000);
    gpas.insert("Lucy", 2.956);
    assert(gpas.contains(""));
    gpas.erase("Ethel");
    assert(gpas.size() == 3  &&  gpas.contains("Lucy")  &&  gpas.contains("Ethel")  &&
           gpas.contains(""));
    
    */
    /*
        assert(m.insert("Fred", 123));
        assert(m.insert("Ethel", 456));
        assert(m.size() == 2);
        double d = 42;
        assert(m.get("Fred", d)  &&  d == 123);
        d = 42;
        string s1;
        assert(m.get(0, s1, d)  &&
               ((s1 == "Fred"  &&  d == 123)  ||  (s1 == "Ethel"  &&  d == 456)));
        string s2;
        assert(m.get(1, s2, d)  &&  s1 != s2  &&
               ((s2 == "Fred"  &&  d == 123)  ||  (s2 == "Ethel"  &&  d == 456)));
*/
    
    /*
    
     assert(m.insert("Drod", 213));
    assert(m.insert("Arod", 213));
    assert(m.insert("Crod", 125));
    assert(m.insert("Brod", 125));
    assert(m.insert("Fred", 123));
    assert(m.insert("Ethel", 456));
    assert(m.size() == 6);
    double d = 42;
    
    m.dump();
    
    
    assert(m.get("Fred", d)  &&  d == 123);
    d = 42;
    
    
    KeyType kk ="Etel";
    KeyType k3 ="Erlj";
    m.get(1,kk, d );
    cerr<< "  \nget key " << kk << " get value " << d;
    
    
    */
  
    
     m1.insert("Drod", 213);
    m1.insert("Arod", 213);
    m1.insert("Crod", 125);
    
    KeyType kk;
    ValueType vv;
    
    cerr<< " m1 dump " <<endl;
    m1.dump();// display m1 have
    
    m2.insert("Crod", 246);
    m2.insert("Frod", 125);
    m2.insert("Brod", 125);
    cerr<< " \nm2 dump " <<endl;
    m2.dump(); // display m2 have
    
    
    
    cerr<< "\nGet function work for m2 "<<endl;
    for(int j=0;j<m2.size();j++)
    {
        m2.get(j, kk, vv);
        cerr<< j <<" key : " << kk << "   value  " << vv<<endl;
    }
    
    
    cerr << "       next .. implement function "<<endl;
    subtract(m1,m2,m3);
    m3.dump();
    cerr << "    next  " << endl;
    combine(m1, m2, m3);
    
    
    m3.dump();
    
    
}
void subtract(const Map& m1, const Map& m2, Map& result)
{
    cerr<< " \nsubtract m1 - m2 = left m1 " << endl;
    KeyType k ="";
    //KeyType k[m1.size()]; // default key and value
    
    ValueType v = 0;
    
    for (int i = 0; i < m2.size(); i++) //Index i is counted untill size of object M1
    {
        m1.get(i, k, v); // get keys and value for each node of object m1
        //cerr << i <<" kkkk "<< k << " vvvvvv " << v << endl;
        
        //if(m2.get(i,k[i],v))
        if(!m2.contains(k))   // if get(i,k,v) == false, their key is different from map
        {
            result.insert(k,v);
            
            //result.dump();
        }
    }
    for (int i = 0; i < m2.size(); i++) //Index i is counted untill size of object M1
    {
        m1.get(i, k, v); // get keys and value for each node of object m1
        //cerr << i <<" kkkk "<< k << " vvvvvv " << v << endl;
        
        //if(m2.get(i,k[i],v))
        if(!m2.contains(k))   // if get(i,k,v) == false, their key is different from map
        {
            result.insert(k,v);
            //result.dump();
        }
    }
    
    //if ( !m2.contains(k)){ // If get(k,v)==false, ma and mb 's keys are different.
    //  result.insert(k, v);//if( m1 key != m2 key), result object takes m1 key
    
}
bool combine(const Map& m1, const Map& m2, Map& result)
{
    cerr<< " \ncombine " << endl;
    bool later= true;
    KeyType k1 = " " ;
    ValueType v1 = 0;
    if (&m1 == &m2) // If they are the same, just return either one.
    {
        result = m1;
        return true;
    }
    
    for(int i = 0; i < m1.size(); i++)
    {
        m1.get(i, k1, v1);  // get keys/val of m1
        if(!m2.contains(k1))
        {
               //cerr<< i <<"sssssdsds " << k1 << "  " << v1 <<endl;
              result.insert(k1,v1);
        }//insert every m1
    }
    for(int j = 0; j < m2.size(); j++)
    {
        m2.get(j, k1, v1);  // get keys/val of m1
       
        if(m1.contains(k1))
        {
            if(!m1.get(k1,v1))  //if m1's key == input keys m1's value == temp->val, return false from get(k, v).
            {
                result.insert(k1,v1);
                //cerr<< "pppppppdsds " << k1 << " v " << v1<<endl;
          
            }
            else
                later = false; //assign false
        }
        else
        {
                result.insert(k1,v1); //insert pairs in m1 except what mc have
                //cerr<< "  hhhhs  " << k1 << " v " << v1;
                
        }
    }
    return later;
}

#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }

static_assert(std::is_default_constructible<Map>::value,
              "Map must be default-constructible.");
static_assert(std::is_copy_constructible<Map>::value,
              "Map must be copy-constructible.");

void ThisFunctionWillNeverBeCalled()
{
    CHECKTYPE(&Map::operator=,      Map& (Map::*)(const Map&));
    CHECKTYPE(&Map::empty,          bool (Map::*)() const);
    CHECKTYPE(&Map::size,           int  (Map::*)() const);
    CHECKTYPE(&Map::insert,         bool (Map::*)(const KeyType&, const ValueType&));
    CHECKTYPE(&Map::update,         bool (Map::*)(const KeyType&, const ValueType&));
    CHECKTYPE(&Map::insertOrUpdate, bool (Map::*)(const KeyType&, const ValueType&));
    CHECKTYPE(&Map::erase,          bool (Map::*)(const KeyType&));
    CHECKTYPE(&Map::contains,       bool (Map::*)(const KeyType&) const);
    CHECKTYPE(&Map::get,            bool (Map::*)(const KeyType&, ValueType&) const);
    CHECKTYPE(&Map::get,            bool (Map::*)(int, KeyType&, ValueType&) const);
    CHECKTYPE(&Map::swap,           void (Map::*)(Map&));
    
    CHECKTYPE(combine,  bool (*)(const Map&, const Map&, Map&));
    CHECKTYPE(subtract, void (*)(const Map&, const Map&, Map&));
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}


