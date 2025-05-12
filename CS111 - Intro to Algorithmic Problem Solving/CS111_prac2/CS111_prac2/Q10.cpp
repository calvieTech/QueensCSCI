//
//  Q10.cpp
//  CS111_prac2
//
//  Created by Calvin Thang on 7/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

void up(int x[][3], int rows, int cols) {
    for (int c = 0; c < cols; c++) for (int r = 0; r < rows; r++)
        cout << 10 + x[r][c];
    cout << endl;
}

int main() {
    int x[3][3] = {{3, 1, 4}, {1, 5, 9}, {2, 6, 5}};
    
    
    cout << x[2][2] << endl; //output: 5
    cout << x[x[2][0]][x[2][0]] << endl; //output: 5
    for (int r = 0; r < 2; r++) cout << x[2][r] << endl; //output: 2
                                                        // 6
    up(x, 1, 1); // output: 13
    up(x, 2, 2); // output: 13111115
}
