//
//  main.cpp
//  cs30_nonVirtualInterface
//
//  Created by Jinhan Han on 4/23/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
   getdound() const {return"dd";};
    void speak() const
    {
        
        cout <<"\n we can put extra work before the sound() or after sound()" << endl;
        cout << getSound() << endl;
        cout <<"ending the sound" << endl;
    }
    
private:
    
};

class Dog : public Animal
{
public:
    std::string getSound() const { return "wolf!"; }
private:
    std::string getBehavior() const { return "Run and run!"; }
    //std::string getSound() const { return "Woof!"; }
};

class Cat : public Animal
{
    public:
    std::string getSound() const { return "Meow!"; }
std::string getBehavior() const { return "catch mouse!"; }
private:
    //std::string getSound() const { return "Meow!"; }
};
/*
class Duck : public Animal
{
    
private:
    std::string getSound() const { return "quack!"; }
};
 */



int main(int argc, const char * argv[]) {
    
    Cat c;
    Dog d;
    
    Animal *a = new Cat;
    std::cout << "Hello, World!\n";
    d.speak();
    c.speak();
    a->speak();
    return 0;
}
