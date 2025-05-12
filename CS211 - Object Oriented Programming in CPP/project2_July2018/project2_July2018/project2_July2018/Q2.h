//
//  Q2.h
//  project2_July2018
//
//  Created by Calvin Thang on 7/31/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#ifndef Q2_h
#define Q2_h
#include <iostream>
#include <string>
using namespace std;

class Message1{
public:
    Message1() {
        _date = 0;
    }
    
    Message1(string f) {
        _from = addDomain(f);
        _date = 0;
    }
    
    Message1(string f, string t) {
        _from = addDomain(f);
        _to = addDomain(t);
        _date = 0;
    }
    
    Message1(string f, string t, string s) {
        _subject = s;
        _from = addDomain(f);
        _to = addDomain(t);
    }
    
    Message1(string f, string t, string s, string txt) {
        _text = txt;
        _from = addDomain(f);
        _to = addDomain(t);
        _subject = s;
    }
    
    string from() const {
        return _from;
    }
    
    string to() const {
        return _to;
    }
    
    string subject() const {
        return _subject;
    }
    
    string text() const {
        return _text;
    }
    
    string date() const {
        return string("n/a");
    }
    
    
    void setSubject(string s) {
        _subject = s;
    }
    
    void setText(string txt) {
        _text = txt;
    }
    
    void prependText(string input) {
        string blank = " ";
        _text = input + blank + _text;
    }
    
    void appendText(string t) {
        string blank = " ";
        _text = _text + blank + t;
    }
    
    void setRecipient(string t) {
        _to = addDomain(t);
    }
    
    void print() const {
        cout << "From: " << _from << endl;
        cout << "To: " << _to << endl;
        cout << "Subject: " << _subject << endl;
        cout << "Date: " << date() << endl;
        cout << _text << endl;
        cout << endl;
    }
    
    
    
    
    
    
private:
    string _from;
    string _to;
    string _subject;
    string _text;
    int _date;
    
    string addDomain(string s) {
        const string _domain = "@qc.cuny.edu";
        istringstream iss(s); //istringstream removes leading and trailing blanks from s
        iss >> s;
        string email = s + _domain;
        return email;
    }
    
};


ostream& operator<< (ostream& os, const Message1 &m) {
    os << "From: " << m.from() << endl;
    os << "To: " << m.to() << endl;
    os << "Subject: " << m.subject() << endl;
    os << "Date: " << m.date() << endl;
    os << m.text() << endl;
    return os;
}



#endif /* Q2_h */
