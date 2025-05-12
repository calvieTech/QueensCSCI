//
//  Q3.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

double averageOdd(int data[][3], int r, int c) {
    double sum = 0;
    int counter = 0;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (data[x][y] % 2 != 0) {
                sum += data[x][y];
                counter += 1;
            }
        }
    }
    if (counter == 0) return 0;
    return (sum / (double) counter);
    
    
}



int main() {
    int data[2][3] = {{3, 1, 4}, {2, 7, 1}};
    cout << averageOdd(data, 2, 3) << endl; // prints 3.0
    
    return 0;
    
    
    
    
}
