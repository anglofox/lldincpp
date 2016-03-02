//
//  main.cpp
//  map
//
//  Created by Angela Fox on 3/1/16.
//  Copyright © 2016 Angela Fox. All rights reserved.
//
#include <iostream>
#include <vector>
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
    vector<int> randomInt;
    while (randomInt.size() < NUMBER) {
        int j = insertDist(generator);
        bool found = (find(randomInt.begin(), randomInt.end(), j) != randomInt.end());
        if (!found) {
            randomInt.push_back(j);
        }
    }
    
    //Create list myList
    vector<int> myVector;
    int k;
    
    //Fill myList with random ints, inserting each in order
    myVector.push_back(randomInt.back());
    cout << ' ' << myVector.back() << endl;
    randomInt.pop_back();
    while(!randomInt.empty()) {
        k = randomInt.back();
        randomInt.pop_back();
        if (k > myVector.back()) {
            myVector.push_back(k);
        } else {
            for (vector<int>::iterator it1 = myVector.begin(); it1 != myVector.end(); ++it1) {
                if (k < *it1) {
                    myVector.insert(it1, k);
                    break;
                }
            }
        }
        //Print out list
        for (vector<int>::iterator it2 = myVector.begin(); it2 != myVector.end(); ++it2)
        {
            cout << ' ' << *it2;
        }
        cout << '\n';
        
    }
    
    //Generate random remove sequence and remove at that point
    vector<int>::iterator it3;
    
    for(int num = NUMBER-1; num >= 0; --num){
        uniform_int_distribution<int> removeDist(0,num);
        int removeIndex = removeDist(generator);
        cout << "remove position: " << removeIndex << endl;
        it3 = myVector.begin();
        for (int n = 0; n<removeIndex; n++)
        {
            it3++;
        }
        it3 = myVector.erase(it3);
        
        //Print out list
        for (vector<int>::iterator it4 = myVector.begin(); it4 != myVector.end(); ++it4)
        {
            cout << ' ' << *it4;
        }
        cout << '\n';
    }
    return 0;
}


