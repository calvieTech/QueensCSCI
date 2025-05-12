//
//  Pt1_Q3.h
//  project3
//
//  Created by Calvin Thang on 8/13/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#ifndef Pt1_Q3_h
#define Pt1_Q3_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>
#include <locale>

using namespace std;

class Name {
public:
    Name() {}
    Name(string s) { set(s); }
    void set(string s); // mutator
    string name() const { return _name; } // accessor
    string address() const { return _address; } // accessor
    
    
private:
    string _name;
    string _address;
};

void Name::set(string s) {
    const string _domain = "@qc.cuny.edu";
    istringstream iss(s);
    iss >> _name;
    if (_name == "") {
        _address = "";
        return;
    }
    else {
        _address = _name + _domain;
        for (int i = 0; i < _address.size(); ++i)
            _address[i] = tolower(_address[i]);
        return;
    }
}


#endif /* Pt1_Q3_h */
