#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>
#include <locale>
#include <ctime>
#include <map>
#include "proj3.hpp"
using namespace std;

template<class T>
void Vec<T>::clear() {
    _size = 0;
}

template<class T>
void Vec<T>::pop_back() {
    if (_size > 0) _size -= 1;
}

template<class T>
void Vec<T>::push_back(const T &a) {
    
    if (_capacity > _size) {
        _vec[_size] = a;
        _size += 1;
        return;
    }
    
    if (_size == _capacity) {
        if (_capacity == 0) {
            _capacity = 1;
        }
        
        else {
            _capacity *= 2;
        }
        
        T *oldvec = _vec;
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

template<class T>
T& Vec<T>::at(int n) {
    if ((n >= 0) && (n < _size)) return _vec[n];
    else {
        T *ptr = NULL;
        return *ptr;
    }
}

template<class T>
T& Vec<T>::operator[](int n) {
    return at(n);
}

template <class T>
const T& Vec<T>::operator[](int n) const {
    if (n >= 0 && n < _size) {
        return _vec[n];
    }
    
    else {
        T *pnull = NULL;
        return *pnull;
    }
}

template<class T>
void Vec<T>::release() {
    if (_vec != NULL) {
        delete [] _vec;
    }
    _vec = NULL;
}

template<class T>
void Vec<T>::allocate() {
    if (_capacity > 0)
        _vec = new T[_capacity];
    else
        _vec = NULL;
}

template<class T>
T Vec<T>::front() const {
    if (_size <= 0) return 0;
    else return _vec[0];
}

template<class T>
T Vec<T>::back() const {
    if (_size <= 0) return 0;
    else return _vec[_size-1];
}



template<class T>
Vec<T>::Vec() : _capacity(0), _size(0), _vec(NULL) {}

template<class T>
Vec<T>::Vec(int n) {
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



template<class T>
Vec<T>::Vec(int n, const T &a) {
    if (n <= 0) {
        _capacity = 0;
        _size = 0;
        _vec = NULL;
    }
    
    else {
        _capacity = n;
        _size = n;
        allocate();
        for (int i = 0; i < _size; i++) {
            _vec[i] = a;
        }
    }
}

template<class T>
Vec<T>::Vec(const Vec &orig) {
    _capacity = orig.capacity();
    _size = orig.size();
    allocate();
    
    for (int i = 0; i < _size; i++) {
        _vec[i] = orig._vec[i];
    }
}

template<class T>
Vec<T>& Vec<T>::operator= (const Vec<T> &rhs) {
    if (this == &rhs) return *this;
    
    _capacity = rhs.capacity();
    _size = rhs.size();
    release();
    allocate();
    
    for (int i = 0; i < _size; i++)
        _vec[i] = rhs._vec[i];
    return *this;
}

template<class T>
Vec<T>::~Vec() {
    delete [] _vec;
}

template<class T>
void Vec<T>::erase(int n) {
    if (n >= 0 && n < _size) {
        for (int i = n; i < _size-1; ++i) {
            _vec[i] = _vec[i+1];
        }
        _size = _size - 1;
        return;
    }
    else {
        return;
    }
}

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

bool operator==(const Name &n1, const Name &n2) {
    if (n1.address() == n2.address()) return true;
    else return false;
}

bool operator<(const Name &n1, const Name &n2) {
    if (n1.address() < n2.address()) return true;
    else return false;
}






int main() {
    
    /*
     Name n1, n2;
     n1.set("caLvIn");
     n2.set("peTeR");
     
     cout << operator==(n1, n2) << endl;;
     
     Name n3, n4;
     n3.set("aBe");
     n4.set("kiKi");
     
     cout << operator<(n3, n4) << endl;
     */
    
    
    
    return 0;
}
