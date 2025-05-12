//
//  Q3.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

void sumDiff(int one[], int two[], int c) {
    int temp;
    for (int i = 0; i < c; i++) {
        temp = one[i] + two[i];
        two[i] = one[i] - two[i];
        one[i] = temp;
    }
    
}



int main() {
    int one[4] = {7, 6, 8, 4};
    int two[4] = {2, 6, 3, 9};
    sumDiff(one, two, 4);  // one now stores {9, 12, 11, 13}
                            // two now stores {5, 0, 5, -5}
    return 0;
    
    
    
}
