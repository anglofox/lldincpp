//
//  main.cpp
//  list.cpp
//
//  Created by Angela Fox on 3/1/16.
//  Copyright © 2016 Angela Fox. All rights reserved.
//

#include <iostream>
#include <list>
#include <random>
#include <chrono>
#include <algorithm> //for std::find()

using namespace std;

//Number of integers to be inserted into list
#define NUMBER 4

int main() {
    
    //Random Number Generator SetUp - uniform distribution
    //between 0 and 9 using a time seed
    
    typedef chrono::high_resolution_clock myClock;
    myClock::time_point beginning = myClock::now();
    
    myClock::duration d = myClock::now()-beginning;
    unsigned seed = (unsigned)d.count();
    
    default_random_engine generator(seed);
    uniform_int_distribution<int> insertDist(0,9);
    
    //make list of N distinct random integers
    
    list<int> randomInt;
    while (randomInt.size() < NUMBER) {
        int j = insertDist(generator);
        bool found = (find(randomInt.begin(), randomInt.end(), j) != randomInt.end());
        if (!found) {
            randomInt.push_back(j);
        }
    }
    
    //Create list myList
    list<int> myList;
    int k;
    
    //Fill myList with random ints, inserting each in order
    myList.push_back(randomInt.back());
    cout << ' ' << myList.back() << endl;
    randomInt.pop_back();
    while(!randomInt.empty()) {
        k = randomInt.back();
        randomInt.pop_back();
        if (k > myList.back()) {
            myList.push_back(k);
        } else {
            for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
                if (k < *it) {
                    myList.insert(it, k);
                    break;
                }
            }
        }
        //Print out list
        for (list<int>::iterator it3 = myList.begin(); it3 != myList.end(); ++it3)
        {
            cout << ' ' << *it3;
        }
        cout << '\n';
        
    }
    
    //Generate random remove sequence and remove at that point
    list<int>::iterator it2;
    
    for(int num = NUMBER-1; num >= 0; --num){
        uniform_int_distribution<int> removeDist(0,num);
        int removeIndex = removeDist(generator);
        cout << "remove position: " << removeIndex << endl;
        it2 = myList.begin();
        for (int n = 0; n<removeIndex; n++)
        {
            it2++;
        }
        it2 = myList.erase(it2);
        
        //Print out list
        for (list<int>::iterator it4 = myList.begin(); it4 != myList.end(); ++it4)
        {
            cout << ' ' << *it4;
        }
        cout << '\n';
    }
    return 0;
}
