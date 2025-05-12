//
//  Q7.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

void parity(int one[], bool two[], int c) {
    for (int i = 0; i < c; i++) {
        if (one[i] % 2 == 0) {
            two[i] = true;
        }
        else {
            two[i] = false;
        }
    }
}



int main() {
    int one[4] = {7, 6, 8, 4};
    bool two[4];
    
    parity(one, two, 4); // two now stores {false, true, true, true}
    
    return 0;
}
