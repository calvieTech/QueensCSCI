//
//  Q4.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

void display(int x) {
    if (x <= 0) return;
    display(x/10);
    for (int i = 1; i <= x%10; i++) cout << i;
    cout << endl;
    
    
    
    
}


int main() {
    display(31415);
    return 0;
    
}
