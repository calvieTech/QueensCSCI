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
#include "Pt5_Q1.h"

using namespace std;

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


EmailAccount::EmailAccount(string s) {
    _owner.set(s);
    _drafts = new Drafts(this);
    _in = new Inbox(this);
    _out = new Outbox(this);
    ISP::addAccount(this);
}

EmailAccount::~EmailAccount() {
    delete _drafts;
    delete _in;
    delete _out;
}

EmailAccount::EmailAccount(const EmailAccount &orig) {
    _owner = orig._owner;
    _drafts = orig._drafts;
    _in = orig._in;
    _out = orig._out;
}

EmailAccount& EmailAccount::operator=(const EmailAccount &rhs) {
    if (this == &rhs) return *this;
    delete _drafts;
    delete _in;
    delete _out;
    _owner = rhs._owner;
    _drafts = rhs._drafts;
    _in = rhs._in;
    _out = rhs._out;
    return *this;
}

void EmailAccount::receive(Message *m) {
    _in->receive(m);
}

void EmailAccount::insert(Message *m) {
    _drafts->addDraft(m);
}

void EmailAccount::send(Message *m) {
    _out->receive(m);
    ISP::send(m);
}


int main() {
    
    
    
    return 0;
}
