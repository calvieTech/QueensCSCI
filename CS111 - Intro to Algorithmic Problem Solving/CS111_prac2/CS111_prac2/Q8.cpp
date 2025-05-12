//
//  Q8.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int interweaveDigits(int a, int b) {
    if (b < 10) return b * 10 + a;
    return interweaveDigits(a/10, b/10) * 100 + interweaveDigits(a%10, b%10);
}


int main() {
    cout << interweaveDigits(2, 1) << endl; // prints 12
    cout << interweaveDigits(302, 117) << endl; // prints 131072
    cout << interweaveDigits(2468, 1357) << endl; // prints 12345678
    return 0;
    
}
