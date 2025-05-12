//
//  Q16.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int digitDifferences(int a, int b) {
    if (a <= 0 || b <= 0) return 0;
    int diff = a % 10 - b % 10;
    if (diff < 0) diff = -diff;
    return 10 * digitDifferences(a/10, b/10) + diff;
    
    
}



int main() {
    cout << digitDifferences(162, 538) << endl; // prints 436
    return 0;
}
