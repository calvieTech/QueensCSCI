//
//  main.cpp
//  hw2
//
//  Created by Calvin Thang on 10/29/17.
//  Copyright © 2017 Calvin Thang. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int hours;
    double hourly_wage,
    gross_pay,
    deductions,
    net_pay;
    
    cout << "Please enter the number of hours you worked: ";
    cin >> hours;
    
    if (hours < 0) {
        cout << "You have entered a negative number for worked hour." << endl;
        cout << "Terminating the program" << endl;
        exit(0);
    }
    
    cout << "Please enter your hourly wage: ";
    cin >> hourly_wage;
    
    while (hourly_wage < 0) {
        cout << "Your hourly wage is less than 0. Please try again: " << endl;
        cin >> hourly_wage;
    }
    
    
    if (hours <= 40) {
        gross_pay = hours * hourly_wage;
    }
    
    else {
        gross_pay = 40 * hourly_wage + (hours - 40) * hourly_wage * 1.5;
     }
    
    if (gross_pay <= 100) {
        deductions = gross_pay * .02;
    }
    
    else if (gross_pay > 100 && gross_pay < 500) {
        deductions = .05 * gross_pay;
    }
    
    else {
        deductions = .09 * gross_pay;
    }
    
    net_pay = gross_pay - deductions;
    
    cout << "Wage Calculator" << endl;
    cout << endl;
    cout << "Hours Worked:     " << hours << endl;
    cout << "Hourly Wage:      " << hourly_wage << endl;
    cout << "------------------" << endl;
    cout << "Gross Pay:        " << gross_pay << endl;
    cout << "Deductions:       " << deductions << endl;
    cout << "------------------" << endl;
    cout << "Net Pay:          " << net_pay << endl;
    
    
    
    
    
    
    return 0;
}
