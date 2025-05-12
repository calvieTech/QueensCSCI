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



//public copy constructor
Message::Message(const Message &orig) {
    _from = orig._from;
    _to = orig._to;
    _subject = orig._subject;
    _text = orig._text;
    _date = orig._date;
    
}

Message::Message(string f) {
    _from.set(f);
    _date = 0;
}

Message::Message(string f, string t) {
    _from.set(f);
    _to.set(t);
    _date = 0;
}

Message::Message(string f, string t, string s) {
    _from.set(f);
    _to.set(t);
    _subject = s;
    _date = 0;
}

Message::Message(string f, string t, string s, string txt) {
    _from.set(f);
    _to.set(t);
    _subject = s;
    _date = 0;
    _text = txt;
    
}

void Message::setDate() {
    auto t_now = std::chrono::system_clock::now();
    _date = std::chrono::system_clock::to_time_t(t_now);
}

void Message::send() { setDate(); }

void Message::prependText(string input) {
    string blank = " ";
    _text = input + blank + _text;
}

void Message::appendText(string t) {
    string blank = " ";
    _text = _text + blank + t;
}

string Message::date() const {
    if (_date > 0)
        return std::ctime(&_date); // possible compiler warning or error
    else
        return "";
}



void Message::print() const {
    cout << "From: " << _from.name() << " <" << _from.address() << ">" << endl;
    cout << "To: " << _to.name() << " <" << _to.address() << ">" << endl;
    cout << "Subject: " << _subject << endl;
    cout << "Date: " << date() << endl;
    cout << _text << endl;
    cout << endl;
}


int main() {
    /*
     Message testing("Calvin", "Sateesh", "Project3", "This is for Project 3");
     testing.send();
     testing.print();
     */
    
    
    return 0;
}
