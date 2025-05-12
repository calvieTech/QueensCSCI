//
//  Q8.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

void display(int n) {
    if (n <= 0) return;
    display(n/10);
    for (int i = 9; i >= 1; i--) {
        if (i <= n % 10) cout << "X";
        else cout << " ";
    }
    cout << endl;
    
    
}


int main() {
    
    display(31415);
    return 0;
    
    
}
