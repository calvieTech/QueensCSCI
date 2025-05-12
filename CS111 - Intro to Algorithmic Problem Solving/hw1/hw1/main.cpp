//
//  main.cpp
//  hw1
//
//  Created by Calvin Thang on 10/28/17.
//  Copyright © 2017 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;


int trapezoid() {
    
    float h, b1, b2;
    double area;
    
    cout << "What is the height of the trapezoid? ";
    cin >> h;
    cout << endl;
    
    cout << "What is the base 1 of the trapezoid? ";
    cin >> b1;
    cout << endl;
    
    cout << "What is the base 2 of the trapezoid? ";
    cin >> b2;
    cout << endl;
    
    area = .5 * h * (b1 + b2);
    cout << "The area of the trapezoid is: " << area << endl;
    return area;
}


int main() {
    float available_credit,
    max_credit,
    used_credit;
    
    cout << "Enter the customer's maximum credit" << endl;
    cin >> max_credit;
    
    cout << "Enter the amount of credit used by the customer" << endl;
    cin >> used_credit;
    
    available_credit = max_credit - used_credit;
    
    cout << "The available credit is: " << available_credit << endl;
    
    trapezoid();
    
    return 0;
}


