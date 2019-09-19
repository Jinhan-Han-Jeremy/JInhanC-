//
//  main.cpp
//  tryCatch
//
//  Created by Jinhan Han on 3/5/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//


/*
#include <iostream>
using namespace std;
class Person {
public:
    Person(const char* name) : m_name(name) {
        cout << m_name << endl;
    } ~Person() {
        cout << "~" << m_name << endl;
        try{throw -1;}
    catch(int e){cout << "~gotcha" << endl;}
    } private:
    
    const char* m_name;
};
void funcB() {
    cout << "1" << endl;
    Person x("X");
    Person y("Y");
    cout << "2" << endl;
    return;
}

void funcA() {
    cout << "3" << endl;
    try {
        funcB(); }
    catch (int) {
        cout << "4" << endl;
    }
    
    cout << "5" << endl;
}

int main() {
    try {
        funcA();
    }
    catch (int) {
        cout << "6" << endl;
    }
    catch (...) {
        cout << "7" << endl;
    }
    cout << "8" << endl;
    return 0;
}
*/


/*
#include <iostream>
#include <string>

using namespace std;

//stack unwindies

class Person
{
    public:
        Person(string name) : m_name(name)
    {cout << m_name << " person constructor" << endl; }
~Person()
    {   // 2222- throw 3.0;  never put 'throw' inside destruction.
        cout <<"~"<< m_name << " person destructor" << endl;}
    
private:
    string m_name;
};

void funcB()
{
    cout << "begining function B" << endl;
    Person x{"Russel"};
    Person y{"Singhal"};
    //throw 2;    // Before using throw, you must use catch function
    try{ throw 2; }catch(int){cout <<" I caught it"<< endl; }// 1111-  change throw 2 to throw 2.0
    
    cout << " end function B" << endl;  // after ending the function, destructor works.
}
void funcA()
{
    cout << "begining function A" << endl;
    funcB();
    cout << "end function A" << endl;
}
int main() {
    funcA();
    try{
        funcA();
        throw 1.2;
    }

    catch(int e){ cout << "we caught integer e " << e << endl;}  // 1111-  change int to double
    catch(double e){ cout << "we caught double e " << e << endl;}  // 1111-  change int to double
    
}
*/



 #include <iostream>
 #include <stdexcept> // excpetion class c++11
 using namespace std;
 
 class Example {
 public:
 ~Example() {
 try {
 // Never, ever have a destructor throw an
 // exception
 throw "ddd";
     throw 20;
 }
 catch (...) { cerr << "exception thrown in destructor"<< endl; }
 }
 };
 
 class DivideByZero : public runtime_error {
 public:
 DivideByZero(int numerator, char *s)
     : m_numerator(numerator), runtime_error(s) { fu();
 
 }
 int getNumerator() const { return m_numerator; }
 private:
 int m_numerator;
     
     
     void fff()
     {   cout << " sfsdfsdfsds "<< endl;
         fu();
     }
     void fu()
     {
         
         cout << " sffs "<< endl;
         throw 12;
     }
 };


 int main() {
 
 try {
 Example x;
 int a = 2, b = 0;
 if (b == 0)
     
 throw DivideByZero(a, "divide by zero");
 cout << a / b;
 }
 catch (DivideByZero e) {
 cerr << "ERROR: " << e.what() << endl;
 cerr << "Your numerator is " << e.getNumerator() << endl;
 }
 catch (exception e) {
 cerr << "ERROR: unknown exception" << endl;
 }
 catch (int e) {
 cerr << "ERROR: integer exception thrown: "
 << " error #" << e << endl;
 }
 catch (...) {  // catches everything, shouldn't use awesome
 cerr << "ERROR: unexpected exception" << endl;
 }
 
 }

/*
 #include <iostream>
 #include <stdexcept> // excpetion class c++11
 using namespace std;
 
 class Person
 {
 public:
 char names;
 person(char nname){ cerr << nname << endl;}
 ~person() {cerr << "~ " << nname << endl;}
 };
 int main()
 {
 
 }
 */




/*
using std::string;

string & string::operator=(const char *str)
{
    delete[] s_; //delete data member
    char *s_ = strcpy(new char[strlen(str +1)], str);
    return *this;
}

string & string::operator=(const char *str)
{
    char *temp_ = strcpy(new char[strlen(str +1)], str);
    delete[] s_; //delete data member
    s_=temp;
    return *this;
}
*/
