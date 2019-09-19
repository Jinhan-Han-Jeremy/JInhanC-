//
//  main.cpp
//  jinhan
//
//  Created by Jinhan Han on 10/27/17.
//  Copyright © 2017 Jinhan Han. All rights reserved.
//


//
//  jinhan.cpp
//
//
//  Created by Jinhan Han on 10/26/17.
//

#include <iostream>

using namespace std;

double average(int num, int *arr)
{
    int tot = 0;
    for (int i = 0; i<num; i++)
    {
        tot += arr[i];
    }
    
    double oval = ((double)tot / (double)num);
    
    return oval;
}


void allign_dest(int num, int *arr, int *agn)
{
    int *art;
    art = new int[num];
    for (int i = 0; i<num; i++)
        art[i] = arr[i];
    
    int idx = 0;
    for (int i = 0; i<num; i++)
    {
        int maxval = 0;
        for (int j = 0; j<num; j++)
        {
            if (maxval<art[j])
            {
                maxval = art[j];
                idx = j;
            }
        }
        agn[i] = maxval;
        art[idx] = -1;
    }
    int a = 0;
    delete art;
}


double median(int num, int *agn)
{
    if (num % 2 == 1)
    {
        int midn = num / 2;
        double oval = agn[midn];
        return oval;
    }
    else
    {
        int midn = num / 2;
        
        cout << ((double)(agn[midn] + agn[midn - 1])) / 2.0 << endl;
        
        double oval = ((double)(agn[midn] + agn[midn + 1]))/2.0;
        return oval;
        
        
    }
    
}

int mode(int num, int *agn)
{
    int modecnt = 0;
    int oval = -1;
    
    int modenow = 1;
    for (int i = 1; i<num; i++)
    {
        if (agn[i] == agn[i - 1])
        {
            modenow++;
        }
        else
        {
            if (modenow>modecnt)
            {
                modecnt = modenow;
                oval = agn[i - 1];
            }
            modenow = 1;
        }
    }
    if (agn[num] == agn[num - 1])
    {
        modenow++;
        if (modenow>modecnt)
        {
            modecnt = modenow;
            oval = agn[num];
        }
    }
    
    return oval;
}



int main(int argc, char *argv[])
{
    //a. students number that were surveyed
    int num;
    
    //a. Ask the user how many students were surveyed
    cout << "How many students were surveyed? Type number..." << endl;
    
    //a. Read the number
    cin >> num;
    
    //a. An array of integers with 'num' elements should then be dynamically allocated.
    int *arr;
    arr = new int[num];
    
    //b. Allow the user to enter the number of movies each student saw into the array.
    for (int i = 0; i<num; i++)
    {
        cout << "Enter the number of movies that student " << i << " saw" << endl;
        int inval;
        cin >> inval;
        if (inval<0) // Do not accept neg values!
        {
            cout << "The number can not be negative value." << endl;
            i--;
        }
        else
        {
            arr[i] = inval;
        }
    }
    
    //c. Calculate and display the average
    double avrval = average(num, arr);
    
    //c. for median and mode, align the array
    int *agn;
    agn = new int[num];
    allign_dest(num, arr, agn);
    
    //c. Calculate and display the median
    double medval = median(num, agn);
    
    //c. Calculate and display the mode
    int modval = mode(num, agn);
    
    ////for test
    //    for (int i=0;i<num;i++)
    //        cout << arr[i] << " ";
    //    cout << endl;
    //    for (int i=0;i<num;i++)
    //        cout << agn[i] << " ";
    //    cout << endl;
    ////for test
    
    //c. Display the average, median, mode
    cout << "Average : " << avrval << endl;
    cout << "Median : " << medval << endl;
    cout << "Mode : " << modval << endl;
    cin.get();
    cin.get();
    delete agn;
    delete arr;
    return 0;
}
