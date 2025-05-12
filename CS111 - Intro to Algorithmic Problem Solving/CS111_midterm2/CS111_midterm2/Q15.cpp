//
//  Q15.cpp
//  CS111_midterm2
//
//  Created by Calvin Thang on 7/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;


double percentPositive(double x[][4], int r, int c) {
    int counter = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (x[i][j] > 0) counter += 1;
        }
    }
    double percent = ((double) counter) / (r * c);
    percent = percent * 100;
    return percent;
    
}


int main() {
    double x[2][4] = { {1, -1, -2, -3}, {-4, -5, -6, -7}};
    cout << percentPositive(x, 2, 4) << " percent " << endl; // prints 12.5 percent
    // because the 1 positive number gives 12.5%
    return 0;
}
