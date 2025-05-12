//
//  Pt4_Q1.h
//  project3
//
//  Created by Calvin Thang on 8/14/18.
//  Copyright © 2018 Calvin Thang. All rights reserved.
//

#ifndef Pt4_Q1_h
#define Pt4_Q1_h

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
using namespace std;

class BaseFolder;
class Inbox;
class Outbox;
class Drafts;
class EmailAccount;
class ISP;
class Message;
class Name;
template<class T> class Vec;

//VEC DECLARATIONS
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

//NAME DECLARATIONS
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

//MESSAGE DECLARATIONS
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
    
private:
    void setDate(); // see below
    Name _from; // use "Name" class
    Name _to; // use "Name" class
    string _subject;
    string _text;
    time_t _date; // see below
};


//EmailAccount declarations
class EmailAccount {
public:
    EmailAccount(string s);
    ~EmailAccount();
    
    const Name& owner() const { return _owner; } // accessor
    Drafts& drafts() { return *_drafts; } // accessor/mutator
    BaseFolder& in() { return *_in; } // accessor/mutator
    BaseFolder& out() { return *_out; } // accessor/mutator
    
    void send(Message *m);
    void receive(Message *m);
    void insert(Message *m);
    
    EmailAccount(const EmailAccount &orig);
    EmailAccount& operator=(const EmailAccount &rhs);
    
private:
    Name _owner;
    Drafts * _drafts;
    BaseFolder * _in;
    BaseFolder * _out;
};



//BASE_FOLDER DECLARATIONS
class BaseFolder {
public:
    BaseFolder(EmailAccount *ac);
    int size() const { return _msg.size(); }
    
    void display() const;
    void erase(int n);
    void forward(int n) const;
    void print(int n) const;
    void receive(const Message *m);
    void reply(int n) const;
    
    virtual ~BaseFolder();
    
    
    
protected:
    virtual string type() const = 0; // pure virtual if desired
    virtual const Name& tofrom(const Message *m) const = 0; // pure virtual if desired
    
    // data
    Vec<const Message*> _msg;
    EmailAccount *_ac;
    
private:
    BaseFolder (const BaseFolder &orig);
    BaseFolder& operator= (const BaseFolder &rhs);
    
};



//DRAFTS DECLARATION
class Drafts {
public:
    Drafts(EmailAccount *ac);
    ~Drafts();
    
    void display() const;
    void send(int n);
    void erase(int n);
    
    Message* addDraft();
    Message* addDraft(Message *m);
    Message* getDraft(int n) { return _drafts[n]; }
    Message* operator[](int n) { return _drafts[n]; }
    
    Drafts(const Drafts &orig);
    Drafts& operator=(const Drafts &rhs);
    
    
    
private:
    int newKey();
    
    // data
    int _newKey;
    map<int, Message*> _drafts;
    EmailAccount *_ac;
};

//INBOX DECLARATION
class Inbox : public BaseFolder {
public:
    Inbox (EmailAccount *ac);
    
protected:
    virtual string type() const;
    virtual const Name& tofrom(const Message *m) const;
};

//OUTBOX DECLARATION
class Outbox : public BaseFolder {
public:
    Outbox(EmailAccount *ac); // public constructor
protected:
    virtual string type() const; // override
    virtual const Name& tofrom(const Message *m) const; // override
};

//ISP declarations
class ISP {
public:
    static void addAccount(EmailAccount *e) {
        _accounts[e->owner()] = e;
    }
    static void send(Message *m);
private:
    ISP() {}
    static map<Name, EmailAccount*> _accounts;
};




#endif /* Pt4_Q1_h */
