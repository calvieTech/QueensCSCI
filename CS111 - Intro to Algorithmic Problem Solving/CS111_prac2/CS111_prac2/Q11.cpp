//
//  Q11.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int sum3(int x[], int c) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        if (x[i] > 99 && x[i] < 999) sum += x[i];
    }
    return sum;
    
    
}


int main() {
    int x[6] = {3, 31, 314, 111, 4000, 100};
    cout << sum3(x, 6) << endl; // prints 525
    return 0;
    
    
    
    
}
