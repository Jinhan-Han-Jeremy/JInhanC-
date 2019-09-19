//
//  main.cpp
//  regex
//
//  Created by Jinhan Han on 12/12/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//




#include <iostream>
#include<regex>
using namespace std;

int main()
{
    
    
    string time1= "9:17 am" ;
    string time2 = "17:00 pm";
    string time3="12:30 pm";
    string time4="10:99 am";
    
    
    string number1= "310-­555-2468" ;
    string number2 = "310.555.2345";
    string number3="310 555 9999";
    string number4="2135558765";
    string number5="310-­555.1234";
    
    string nuumber1= "^cat3 e. ast1" ;
    string nuumber2 = "ttt";
    string nuumber3="tttca";
    string nuumber4="cattt";
    string nuumber5="catttca";
    //^cat3 e. ast1, ttt, ttttt, ca,ca, catttca
    
    regex c2("(([0-9]|10|11|12):([0-5][0-9]) ([ap]m))$");
    
    
    regex c1("^(ca)?t{3,}\\1");
    regex r1("^([0-9]{3})-([0-9]{3})-([0-9]{4})"); //regex for 333-333-3333
    regex r2("^[0-9]{3}[.][0-9]{3}[.][0-9]{4}"); //regex for 333.333.3333
    regex r3("^[0-9]{3}[\\s][0-9]{3}[\\s][0-9]{4}"); //regex for 333 333 3333
    regex r4("^[0-9]{10}"); // regex for 3333333333
    
    //if number matched with any of the 4 regex, print matched else not matched
    if(regex_match(number1,r1) || regex_match(number1,r2) || regex_match(number1,r3) || regex_match(number1,r4)|| regex_match(number1,c2)){
        
        cout << "it is 1 " <<endl;
        cout<<"matched"<<endl;
    }
    else{
        cout<<"1 not matched"<<endl;
    }
    if(regex_match(number2,r1) || regex_match(number2,r2) || regex_match(number2,r3) || regex_match(number2,r4)|| regex_match(number2,c2)){
        cout << "it is 2 " <<endl;
        cout<<"matched"<<endl;
    }
    else{
        cout<<"2 not matched"<<endl;
    }
    
    if(regex_match(number3,r1) || regex_match(number3,r2) || regex_match(number3,r3) || regex_match(number3,r4)|| regex_match(number3,c2)){
        cout << "it is 3 " <<endl;
        cout<<"matched"<<endl;
    }
    else{
        cout<<"3 not matched"<<endl;
    }
    
    if(regex_match(number4,r1) || regex_match(number4,r2) || regex_match(number4,r3) || regex_match(number4,r4)|| regex_match(number4,c2)){
        cout << "it is 4 " <<endl;
        cout<<"matched"<<endl;
    }
    else{
        cout<<"4 not matched"<<endl;
    }
    if(regex_match(number5,r1) || regex_match(number5,r2) || regex_match(number5,r3) || regex_match(number5,r4)|| regex_match(number5,c1)){
        cout << "it is 5 " <<endl;
        cout<<"matched"<<endl;
    }
    else{
        cout<<"5 not matched"<<endl;
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>

using namespace std;

int main(void)
{
    string str;
    
    while(1)
    {
    getline(cin, str);
    if(str == "")
        break;
    
    regex e("^([1-9]{3})[-. /]?([1-9]{3})\\1[0-9]{4}");
        //^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$
    //regex e("^(([0-1])?[0-2]):[0-5]?[0-9] (am|pm)$");
    bool match = regex_match(str, e);
    cout << (match ? "matche" : "not matched") << endl << endl;
    }
}
*/
