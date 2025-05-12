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


//TEMPLATE CLASS VEC DEFINITIONS
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

//NAME DEFINITIONS
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




//MESSAGE DEFINITIONS
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


//BASE FOLDER DEFINITIONS
BaseFolder::BaseFolder(EmailAccount *ac) : _ac(ac) {
    _msg.push_back(NULL);
}

void BaseFolder::receive(const Message *m) {
    _msg.push_back(m);
}

void BaseFolder::print(int n) const {
    if (n < 1 || n >= _msg.size()) return;
    else print(n);
}

void BaseFolder::erase(int n) {
    if (n < 1 || n >= _msg.size()) return;
    else {
        delete _msg[n];
        _msg.erase(n);
    }
}

void BaseFolder::display() const {
    cout << _ac->owner().name() << " " << type() << endl;
    if (_msg.size() <= 1) cout << "no messages to display" << endl;
    else {
        for (int i = 1; i < _msg.size(); ++i) {
            Name tmp = tofrom(_msg[i]);
            cout << i << " " <<  tmp.name() << " " << _msg[i]->subject() << endl;
        }
    }
}

void BaseFolder::forward(int n) const {
    if (n < 1 || n >= _msg.size()) return;
    else {
        const Message *m = _msg[n];
        string fwd_subject("Fwd: " + m->subject());
        Message *ptr = new Message(_ac->owner().name(), "", fwd_subject, m->text());
    }
}

void BaseFolder::reply(int n) const {
    if (n < 1 || n >= _msg.size()) return;
    else {
        const Message *m = _msg[n];
        string subject("Re : " + m->subject());
        const Name tmp = tofrom(m);
        Message *ptr = new Message(_ac->owner().name(), tmp.name(), subject, m->text());
        _ac->insert(ptr);
    }
}

BaseFolder::~BaseFolder() {
    for (int i = 0; i < _msg.size(); ++i) {
        delete _msg[i];
    }
    delete _ac;
}


//INBOX DEFINITIONS
Inbox::Inbox(EmailAccount *ac) : BaseFolder(ac) {}

string Inbox::type() const {
    return "inbox";
}

const Name& Inbox::tofrom(const Message *m) const {
    return m->from();
}




//OUTBOX DEFINITIONS
Outbox::Outbox(EmailAccount *ac) : BaseFolder(ac) {}

string Outbox::type() const {
    return "outbox";
}

const Name& Outbox::tofrom(const Message *m) const {
    return m->to();
}



//DRAFTS DEFINITIONS
Drafts::Drafts(EmailAccount *ac) {
    _ac = ac;
    _newKey = 0;
    _drafts[0] = NULL;
}

//recheck
Drafts::~Drafts() {
    map<int, Message*>::iterator m_it;
    for (m_it = _drafts.begin(); m_it != _drafts.end(); ++m_it) {
        delete &m_it;
    }
    delete _ac;
}

//Check
Drafts::Drafts(const Drafts &orig) {
    _newKey = orig._newKey;
    //necessary below or not?
    _ac = orig._ac;
    int length = orig._drafts.size();
    
    for (int i = 1; i <= length; ++i) {
        _drafts[i] = orig._drafts.at(i);
    }
}

Drafts& Drafts::operator=(const Drafts &rhs) {
    if (this == &rhs) return *this;
    _newKey = rhs._newKey;
    
    delete _ac;
    _ac = rhs._ac;
    _drafts.clear();
    int length = rhs._drafts.size();
    for (int i = 1; i <= length; ++i) {
        _drafts[i] = rhs._drafts.at(i);
    }
    return *this;
}

int Drafts::newKey() {
    ++_newKey;
    return _newKey;
}

void Drafts::erase(int n) {
    delete _drafts[n];
    _drafts.erase(n);
}

Message* Drafts::addDraft() {
    int key = newKey();
    Message *ptr = new Message(_ac->owner().name());
    _drafts[key] = ptr;
    return ptr;
}

Message* Drafts::addDraft(Message *m) {
    int key = newKey();
    _drafts[key] = m;
    return m;
}

void Drafts::display() const {
    cout << _ac->owner().name() << " drafts: " << endl;
    if (_drafts.size() <= 1) {
        cout << "no messages to display" << endl;
    }
    else {
        map<int, Message*>::const_iterator mit;
        for (mit = _drafts.cbegin(); mit != _drafts.cend(); ++mit) {
            if (mit->first == 0) continue;
            Message *ptr = mit->second;
            cout << mit->first << " " << ptr->to().name() << " " << ptr->subject() << endl;
        }
    }
}




//ISP definition
void ISP::send(Message *m) {
    EmailAccount *ac = _accounts[m->to()];
    if (ac == NULL) {
        cout << "Delivery failed, to recipient: " << m->to().name() << endl;
        return;
    }
    else {
        Message *copy = new Message(*m);
        ac->receive(copy);
        return;
    }
}
 

map<Name, EmailAccount*> ISP::_accounts;


//EmailAccount Definitions
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
