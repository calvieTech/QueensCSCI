//
//  Q4.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;


int interlaceDigits(int a, int b) {
    if (a < 10) return a * 10 + b;
    return interlaceDigits(a/10, b/10) * 100 + interlaceDigits(a%10, b%10);
}



int main() {
    cout << interlaceDigits(1, 2) << endl; // prints 12
    cout << interlaceDigits(117, 302) << endl; // prints 131072
    cout << interlaceDigits(1357, 2468) << endl; // prints 12345678
    return 0;
}
