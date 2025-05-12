#include "Pt1_Q4.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>
#include <locale>
#include <ctime>
using namespace std;


class Message {
public:
    Message(string f);
    Message(string f, string t);
    Message(string f, string t, string s);
    Message(string f, string t, string s, string txt);
    
    const Name& from() const { return _from; }
    const Name& to() const { return _to; }
    
    string subject() const { return _subject; }
    string text() const { return _text; }
    string date() const; // see below
    
    void send(); // see below
    void setRecipient(string t) { _to.set(t); }
    void setSubject(string s) { _subject = s; }
    void setText(string txt) { _text = txt; }
    
    void prependText(string t); // see Message1 class
    void appendText(string t); // see Message1 class
    void print() const; // see Message1 class
    
    //public copy constructor
    Message(const Message &orig);
    
private:
    void setDate(); // see below
    Name _from; // use "Name" class
    Name _to; // use "Name" class
    string _subject;
    string _text;
    time_t _date; // see below
};

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


