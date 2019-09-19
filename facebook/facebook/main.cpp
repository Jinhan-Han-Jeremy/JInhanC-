//
//  main.cpp
//  facebook
//
//  Created by Jinhan Han on 11/14/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void printFacebook(map<string, vector<string>>& m)
{
    for (pair <string, vector<string>> p : m)
    {
        cout <<" " <<p.first <<"'s friend : "<< endl;
        
        for (string f : p.second)
        {cout << "\t" << f << endl;}
    }
}

void printContacts(map<string, vector<pair<string, string>>>& contacts)
{
    
    for (auto it= contacts.begin(); it!= contacts.end(); it++)
    {
        //cout <<" " <<it <<endl;
        cout << "w  " <<it->first.c_str() <<endl;
        vector <pair<string,string>> temp =it -> second;
        
        for (int i = 0; i < temp.size(); i++)
        {
            cout<<temp[i].first << ": "<<temp[i].second<< endl;
        }
    }
}


int main()
{

    map<string, vector<pair<string, string>>> contacts;
    contacts["Jerry"].emplace_back("home", "212312222");
    contacts["Jerry"].emplace_back("cell", "111111111");
    contacts["Sarah"].emplace_back("email","hajamam@gmail.com");
    contacts["Sarah"].emplace_back("cell","2325556668");
    printContacts(contacts);

    
    cout <<"\n\n"<< endl;
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

