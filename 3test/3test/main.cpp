//
//  main.cpp
//  3test
//
//  Created by Jinhan Han on 11/9/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;

void printContacts(map<string, vector<pair < string, string>>>& contacts)
{
    for( auto it = contacts.begin(); it != contacts.end(); it ++)// contact.begin()//??
    {
        cout << it->first <<endl; //(*it).first
        
        for(vector<pair < string, string>>::iterator it2 = (it-> second).begin(); it2 != (it->second).end(); it2++) //auto
        {// it2 = (it ->second).begin(); it2 != (it-> second).end();//??
            cout << " " << it2-> first<< " " << it2-> second <<endl;
        }
    }
    
    /*for(<string, vector<pair < string, string>>> X : contacts)
     cout << x.first<< endl;
     for(auto y : x.seeseeund)
     */
}

int main()
{
    map<string, vector<pair < string, string>>> contacts;
    
    contacts["Jerry"].emplace_back("home:", "31044444");
    contacts["Jerry"].emplace_back("cell:", "21344444");
    contacts["Sarah"].emplace_back("email:", "selco@elco.edu");
    contacts["Sarah"].emplace_back("cell:", "81844444");
    printContacts(contacts);
}
/*
 #include <iostream>
 #include <vector>
 #include <string>
 #include <map>
 using namespace std;
 
 void printFacebook(map<string, vector<string>>& m)
 {
 for (pair <string, vector<string>> p : m)
 {
 cout <<"it " <<p.first << endl;
 
 for (string f : p.second)
 {cout << "\t" << f << endl;}
 }
 }
 
 int main()
 {
 map<string, vector<string>> facebook;
 
 facebook["Syndy"].push_back("James");
 facebook["Syndy"].push_back("jasmin");
 facebook.find("Syndy")->second.push_back("Phuong");
 
 //auto f = facebook.find("Syndy");
 map<string, vector<string>>::iterator f = facebook.find("Syndy");
 
 f->second.push_back("jji");
 
 facebook["Germaine"];
 facebook.find("Germaine")->second.push_back("Agatha");
 facebook.find("Germaine")->second.push_back("Anges");
 facebook.find("Germaine")->second.push_back("Jack");
 
 printFacebook(facebook);
 }
 
 */
