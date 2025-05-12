//
//  Q2.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/14/18.
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
    int a[6] = {5, 3, 1, 4, 4, 1};
    int b = 5, c = 2;
    
    cout << a[b] + a[c] << endl; // output: 2
    cout << fun(b, c) << endl; // output: 5
    for (int r = 3; r <= 5; r++) cout << fun(r, c); // output: 345
    cout << endl;
    fun(a[5], a[4]); cout << a[4] << endl; // output: 4
    cout << fun(a[1], a[3]); cout << a[3] << endl; // output: 44
    
    return 0;
}
