#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "Q2.h"
using namespace std;


class Vec_Message1 {
public:
    Vec_Message1() {
        _capacity = 0;
        _size = 0;
        _vec = NULL;
    }
    Vec_Message1(int n) {
        if (n <= 0) {
            _capacity = 0;
            _size = 0;
            _vec = NULL;
        }
        else {
            _capacity = n;
            _size = n;
            allocate();
        }
    }
    Vec_Message1(int n, Message1 a) {
        if (n <= 0) {
            _capacity = 0;
            _size = 0;
            _vec = NULL;
        }
        else {
            _capacity = n;
            _size = n;
            allocate();
            for (int i = 0; i < _capacity; i++) {
                _vec[i] = a;
            }
        }
    }
    
    Vec_Message1(const Vec_Message1 &orig) {
        _capacity = orig._capacity;
        _size = orig._size;
        allocate();
        
        for (int i = 0; i < _size; i++) {
            _vec[i] = orig._vec[i];
        }
    }
    
    Vec_Message1& operator= (const Vec_Message1 &rhs) {
        if (this == &rhs) return *this;
        
        _capacity = rhs.capacity();
        _size = rhs.size();
        release();
        allocate();
        
        for (int i = 0; i < _size; i++) {
            _vec[i] = rhs._vec[i];
        }
        return *this;
    }
    
    ~Vec_Message1() {
        release();
    }
    
    int capacity() const {
        return _capacity;
    }
    
    int size() const {
        return _size;
    }
    
    Message1 front() const {
        if (_size > 0) return _vec[0];
        else {
            Message1 default_obj;
            return default_obj;
        }
    }
    Message1 back() const {
        if (_size > 0) return _vec[_size-1];
        else {
            Message1 default_obj;
            return default_obj;
        }
    }
    
    
    void clear() {
        _size = 0;
    }
    
    void pop_back() {
        if (_size > 0) _size -= 1;
    }
    
    void push_back(const Message1 &a) {
        if (_capacity > _size) {
            _vec[_size] = a;
            _size += 1;
            return;
        }
        
        if (_size == _capacity) {
            if (_capacity == 0)
                _capacity = 1;
            else
                _capacity *= 2;
            
            Message1 *oldvec = _vec;
            allocate();
            
            if (oldvec != NULL) {
                for (int i = 0; i < _size; ++i) {
                    _vec[i] = oldvec[i]; // deep copy
                }
            }
            delete [] oldvec;
            
            _vec[_size] = a;
            _size++;
        }
    }
    
    Message1& at(int n) {
        if (n >= 0 && n < _size) {
            return _vec[n];
        }
        
        else {
            Message1 *pnull = NULL;
            return *pnull;
        }
    }
    
    Message1& operator[] (int n) {
        return at(n);
    }
    
    
    const Message1& operator[] (int n) const {
        if (n >= 0 && n < _size) {
            return _vec[n];
        }
        
        else {
            Message1 *pnull = NULL;
            return *pnull;
        }
    }



    
    
    
private:
    void allocate() {
        if (_capacity <= 0) _vec = NULL;
        else _vec = new Message1[_capacity];
    }
    
    void release() {
        if (_vec == NULL) return;
        else {
            delete [] _vec;
            _vec = NULL;
        }
    }
    
    int _capacity;
    int _size;
    Message1 * _vec;
};






void reverse(Vec_Message1 &v) {
    int n = v.size();
    Message1 x;
    Vec_Message1 temp(n, x);
    if (n <= 1) return;
    
    for (int i = 0; i < n/2; i++) {
        temp[i] = v.at(i);
        v.at(i) = v.at(n-1-i);
        v.at(n-1-i) = temp[i];
    }
}

void print(ostream &os,const Vec_Message1 &v) {
    int sz = v.size();
    
    for (int i = 0; i < sz; i++) {
        os << i << ": " << v[i] << endl;
    }
}





int main() {
    Message1 a, b;
    
    
    
    return 0;
    
    
    
    
    
    
}

