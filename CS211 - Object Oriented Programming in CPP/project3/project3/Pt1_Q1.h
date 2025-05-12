//
//  Pt1_Q1.h
//  project3
//
//  Created by Calvin Thang on 8/15/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#ifndef Pt1_Q1_h
#define Pt1_Q1_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

template<class T>
class Vec {
public:
    Vec();
    Vec(int n);
    Vec(int n, const T &a);
    
    Vec(const Vec &orig);
    Vec& operator= (const Vec &rhs);
    ~Vec();
    
    int capacity() const { return _capacity; } // inline
    int size() const { return _size; } // inline
    
    T front() const;
    T back() const;
    
    void clear();
    void pop_back();
    void push_back(const T &a);
    
    T& at(int n);
    T& operator[] (int n);
    const T& operator[] (int n) const;
    
    void erase(int n);
    
private:
    void allocate();
    void release();
    
    int _capacity;
    int _size;
    T * _vec;
};




#endif /* Pt1_Q1_h */
