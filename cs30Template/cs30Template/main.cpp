//
//  main.cpp
//  cs30Template
//
//  Created by Jinhan Han on 4/16/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//
#include <iostream>
using namespace std;

template<typename T>
void f(T& param)
{
    //T a;
    //a = 2;
    cout << param << endl;
}; // for lvalue

template<typename T>
void f2(const T& param)
{
    
}; // for lvalues and rvalues

int main()
{
    //case2
    //  1. if expr's type is a reference, ignore the reference part.
    // 2 . Then we pattern match the expr's type against parameters
    // to determine T
    int x= 27;    // x is an int
    const int cx = x;  // cx is a const int
    const int& rx = x; // rx is reference to a const int
    
    f(x);  // T is int
    f(cx); // T is const int
    f(rx); // T is const int
    f2(3);  //this is an error
    
    
    //case3
    //  1. if expr's type is a reference, ignore the reference part.
    //  2. If, after ignoring the reference ness, expr is const, ignore
    //that too. If it is volaile, also ignore that.
    int x1 = 27 ;
    const int cx1 =x;
    const int& rx1 = x;
    /*g(x1);  // T and param types are both int
    g(cx1); // T and param types are both int
    g(rx1); // T and param types are both int
    */
}

/*

#include <iostream>
#include <array>
#include <vector>
using namespace std;
template <typename T>
class heap
{
    //primary templates
    //explicit template specialization
    //partial template specialization
    
public:
    void push(const T& val);
    T pop();
    bool empty() const
    {
        return h_.empty();
    }
private:
    std::vector<T> h_;
};
//a class template explicit specialization
// or a complete specialization


//it is to pop() char
template<>
class heap<const char *>
{
public:
    void push(const char *pval);
    const char* pop();
    bool empty() const
    {
        return h_.empty();
    }
private:
    std:: vector<const char*> h_;
};

const char * heap<const char*>::pop()
{
    std::pop_heap(h_.begin(),h_.end(), [](const char *a, const char* b){return strcmp(a,b)<0;});
const char *temp = h_.back();
h_.pop_back();
return temp;
}
void heap<const char*> :: push(const char *pval)
{
    h_.push_back(pval);
    std::push_heap(h_.begin(),h_.end(), [](const char *a, const char* b){return strcmp(a,b)<0;});
    //work for numbers only
}



template<typename T>
void heap<T> :: push(const T& val)
{
    h_.push_back(val);
    std::push_heap(h_.begin(), h_.end());
    //work for numbers only
}

template <typename T>
T heap<T>:: pop()
{
    std:: pop_heap(h_.begin(),h_.end());
    T tmp(h_.back());
    h_.pop_back();
    return tmp;
    //work for numbers only
}

constexpr int pow(int base, unsigned exp) noexcept
{
    return (exp==0 ? 1: base *pow(base, exp-1));
}

int main() {
    // insert code here...
    heap<int> h;
    heap<const char*> hs;
     hs.push("Hello");
     hs.push("Bye");
     hs.push("Elcamino");
    cout << hs.pop() << endl;
    
    h.push(3); // *1.5  h.
    h.push(4); // *1.5  h.
    h.push(5); // *1.5  h.
    cout << h.pop()<< endl;
 
    // 1 constexpr auto arraySize2 = 10;
    //array<int, arraySize2> data1;
    
    //cout << pow(2, 3) << endl;
    //int n;
    //cin>> n ;
    //cout << pow(n,3) << endl;
    //static_assert(pow(2,3u) == 8, "something was wrong");
    //return 0;
}
***/
