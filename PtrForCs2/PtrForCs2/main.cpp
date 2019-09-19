//
//  main.cpp
//  PtrForCs2
//
//  Created by Jinhan Han on 2/12/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxsize =5;

int pppp(double *dp2 )
{
    double dda [maxsize] = {11, 12, 13, 14, 15};
    
    for(dp2 = &dda[0]; dp2 < &dda[maxsize]; dp2++)  // name of array + num of sequence
    {
        cout << " what target " << *dp2 <<endl;
        
        if(*dp2 < 0)
        {
            cout << " it's value   " << *dp2 << endl;  //Finding value through * dp
            return *dp2;  // ptr address
        }
        
    }
    return -1;
}

int findFirstNegative(int target[], int n) ///normal array
{
    
    
    for(int *dp = target; dp < target+n; dp++)  // name of array + num of sequence
    {
        cout << " what target " << *dp <<endl;
        
        if(*dp < 0)
        {
            cout << " it's value   " << *dp << endl;  //Finding value through * dp
            return dp-target;  // ptr address
        }
        
    }
    return -1;
}


int main(int argc, const char * argv[])
{
    // insert code here...
    int da[5] ={32, 2 , -14, 26, -48};
    int numb = findFirstNegative(da, 4);
    if(numb==-1)
        cout << "It is not negative" << endl;
    else
    {
        cout << "First neagative is " << da[numb] << endl;
        cout << "It's element number is " << numb << endl;
        
    }
    
    
    cerr << " \n It is new thing" << endl;
        int firstvalue = 5, secondvalue = 15;
        int * p1, * p2, *p3;
        
        p1 = &firstvalue;  // p1 = address of firstvalue  ?? *p1 = firstvalue, p1 = &firstvalue
        p2 = &secondvalue; // p2 = address of secondvalue
    
        *p1 = 10;          // IMPORTANT =>  It assigns value to &preference .
        *p2 = *p1;         //For pointersAnd&reference,  value pointed to by p2 = value pointed to by p1
    cout << "wha1 p1 and p2 " << *p1 <<"   " << *p2 << " first value " << firstvalue << " second value "<< secondvalue << endl;
    *p1 =17;            // IMPORTANT =>  It assigns value to &preference and pointer .
    
    p1 = p2;           //For pointers, p1 = p2 (value of pointer is copied)  //address. p2 value is original
                            // p1 value is changed by p2 ptr so we need to touch p2 to change value of p1.  Overriding can't as a variable!!!
                            // p = &fisrtvalue connected with *p = value but no P1= p2
    cout << "wha2 p1 and p2 " << *p1 <<"   " << *p2 << " first value " << firstvalue << " second value "<< secondvalue << endl;
    p3 = &firstvalue;
    *p3 = 400;   // IMPORTANT =>  assign something to p3 only
     p2 = p3;   // IMPORTANT =>  assign something to p2 only
        *p1 = 20;          // value pointed to by p1 = 20,  *ptr = *ptr2는 나중에 값 할당. *업는건 더 나중에
        
        cout << "\nfirstvalue is " << firstvalue << " ptr p1 " << *p1 << '\n';
        cout << "secondvalue is " << secondvalue << " ptr p2 " << *p2 <<  '\n';
        cout << "\nthirdvalue is " << " ptr p3 " << *p3 <<  '\n';
    int val1 =5, val2=10;
    int *pp1, *pp2, *pp3;
    pp1= &val1;
    pp2= &val2;
    *pp1 =20;
    *pp2 =30;
    pp3= &val1;
    pp1 = pp2;
    *pp3 =40;
    pp2= pp3;
    cout << "\nPP firstvalue is " << val1 << " ptr p1 " << *pp1 << '\n';
    cout << "PP secondvalue is " << val2 << " ptr p2 " << *pp2 <<  '\n';

    
    
    return 0;
}
