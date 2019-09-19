//
//  main.cpp
//  listt2
//
//  Created by Jinhan Han on 11/2/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <thread>
#include <future>

using namespace std;

void theFun(int i, promise<int> &p ) //change &p into &&p //1
{
    try{
        string str("Hello from future");
        throw(logic_error("Exception from future"));
    
        int x = i*2;
        p.set_value(x);
        
    }
    catch(...)
    {
        p.set_exception(current_exception());
    }
}

int main() {
    
    promise<int> prms;
    
    thread th(theFun, 3, std::ref(prms));
    future<int> fut = prms.get_future();
    try{
        cout << " returned from future " << fut.get() << endl;
        
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    //thread th(theFun, 3, std:: move(prms));//1
    cout << "Returned from future " << fut.get() << endl;
    th.join();
    //other code
}
