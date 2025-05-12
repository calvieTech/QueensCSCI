//
//  Q11.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

double percentTrue(bool x[], int c) {
    int counter = 0;
    for (int i = 0; i < c; i++) {
        if (x[i] == 1) counter += 1;
        
    }
    
    double percent = 0;
    percent = (counter / (double) c) * 100;
    return percent;
    
    
}



int main() {
    bool x[8] = { true, false, true, false, true, false, true, true};
    cout << percentTrue(x, 8) << " percent " << endl; // prints 62.5 percent
    // because the 5 true entries make up 62.5% of the array
    return 0;
}
