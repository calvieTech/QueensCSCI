//
//  Q2.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int up(int x[], int c) {
    if (c == 1) cout << x[1];
    if (c < 2) return 23;
    if (c == 2) return x[1];
    return x[c] + up(x, c-1);
}

int main() {
    int x[6] = {3,1,4,1,5,9};
    cout << 3 + x[1] << endl; // a) output is 4
    for (int i = 0; i < 6; i++) cout << x[i]; cout << endl; // b) output: 314159
    cout << up(x,1) << endl; // c) output: 123
    cout << up(x,2) << x[2] << endl; // d) output: 14
    cout << up(x,4) << endl;  // e) output: 7
    
    
    
    
    
    
    return 0;
}
