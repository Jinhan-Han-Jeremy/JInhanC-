//
//  main.cpp
//  cs30_sleep_for
//
//  Created by Jinhan Han on 5/9/18.
//  Copyright © 2018 Jinhan Han. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>
#include <thread>
#include <future>
using namespace std;

int main () {
    
    cout << "Main thread id: " << this_thread::get_id() << endl;
    
    std::vector<std::future<void>> futures;
    for (int i =0; i < 10; i++)
    {
        // could have had std::launch::deferred
        auto fut = std::async(std::launch::async, []()
        {
            
            this_thread::sleep_for(std::chrono::seconds(1));
            
            cout << this_thread::get_id() << " " << endl;
        });
        
        futures.push_back(std::move(fut));
    }
    
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &fut) {
        fut.wait();
    });
    cout << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
