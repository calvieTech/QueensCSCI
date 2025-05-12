//
//  Q10.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;


int fun(int &x, int y) {
    if (x == y) cout << y;
    if (x > y) y++;
    else x++;
    return x;
}


int main() {
    int a[6] = {1, 7, 7, 1, 4, 7};
    int b = 5, c = 2;
    cout << a[b] + a[c] << endl; // output: 14
    cout << fun(b, c) << endl; // output: 5
    for (int r = 3; r <= 5; r++) cout << fun(r, c); // output: 345
    cout << endl;
    fun(a[5], a[4]); cout << a[4] << endl; // output: 4
    cout << fun(a[1], a[3]); cout << a[3] << endl; // output: 71
    
    return 0;
}
