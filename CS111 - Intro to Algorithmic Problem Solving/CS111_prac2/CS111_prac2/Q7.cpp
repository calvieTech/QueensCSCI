//
//  Q7.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int numberNegative (double data[][3], int r, int c) {
    int counter = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (data[i][j] < 0) counter += 1;
        }
    }
    return counter;
    
    
}


int main() {
    double data[2][3] = {{-3.0, 1, 4.5}, {-2.2, 7, 1.4}};
    cout << numberNegative (data, 2, 3) << endl; // prints 2
    
    return 0;
    
    
    
    
}
