//
//  main.cpp
//  perfectfoward
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Widget {
public:
         void addName(const string& newName)
        {
         names.push_back(std::move(newName));
        }
    
    
private:
    vector<string> names;
};

int main() {
    Widget w;
    string s = "Solomon";
    
    
    cout << "dddd";
    w.addName(std::move(s));
    cout << s;
    // s is invalid
}
