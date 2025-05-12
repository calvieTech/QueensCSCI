//
//  Q6.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int up(int x[], int c) {
    if (c == 1) cout << x[1];
    if (c < 2) return 47;
    if (c == 2) return x[1];
    return x[c] + up(x, c-1);
}

int main() {
    int x[6] = {2, 7, 1, 8, 2, 8};
    cout << 3 + x[1] << endl; //output: 10
    for (int i = 0; i < 6; i++) cout << x[i]; cout << endl; //output: 271828
    cout << up(x, 1) << endl; //output: 747
    cout << up(x, 2) << x[2] << endl; //output: 71
    cout << up(x, 4) << endl; //output: 17
    
    return 0;
    
    
    
    
    
    return 0;
}
