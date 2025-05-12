//
//  Q12.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

double sumRatios(int a, int b) {
    if (a <= 0 || b <= 0) return 0;
    return sumRatios(a/10, b/10) + ((double) (a % 10)) / (b % 10);
    
    
    
}


int main() {
    cout << sumRatios(132, 568) << endl; // prints 0.95
    return 0;
}
