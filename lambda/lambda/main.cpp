//
//  main.cpp
//  lambda
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int idNum;
    Person() {}
    Person(string n, int id) : name(n), idNum(id) { }
};

bool operator<(const Person& x, const Person& y) {
    return x.idNum < y.idNum;
}

bool sortbyName(const Person& x, const Person& y) {
    return x.name < y.name;
}
int main() {
    
    vector<Person> vi;
    Person a;
    a.name = "Jack";
    a.idNum = 9;
    vi.push_back(a);
    vi.emplace_back("Jay", 45);     // c++14
    
    // calling sort but relying on the < operator
    sort(vi.begin(), vi.end());
    // using a predicate function
    sort(vi.begin(), vi.end(), sortbyName);
    // using a lambda expression
    sort(vi.begin(), vi.end(), [](const Person& x, const Person& y) {
        return x.name < y.name;
    });
    
    // the return type of is deduced in functions with just one return statement
    auto f = [](const Person& x, const Person& y) {return x.name < y.name;};
    
    // more complicated functions have use -> to specify return type
    
    auto g = [](const Person& x, const Person& y) -> int { if (x.idNum > y.idNum) return x.idNum; return y.idNum; };
        
        // lambdas can be called, though this isn't really useful
        [](int x) { cout << "x is: " << x << endl; }(2);
    }

