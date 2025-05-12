#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
    Vec_Message1(int n, const Message1 &a) {
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
    
    void reverse(Vec_Message1 &v) {
        int n = v.size();
        Message1 *temp = new Message1[n/2-1];
        if (n <= 1) return;
        
        for (int i = 0; i < n/2; i++) {
            temp[i] = v.at(i);
            v.at(i) = v.at(n-1-i);
            v.at(n-1-i) = temp[i];
        }
        delete [] temp;
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

void print(ostream &os,const Vec_Message1 &v) {
    int sz = v.size();
    
    for (int i = 0; i < sz; i++) {
        os << i << ": " << v[i] << endl;
    }
}



int main() {

    Message1 a;
    Message1 b(a);
    b.print();
    Message1 c((Message1(Message1(a))));
    c.print();
    
    a = a = b;
    a = b = a;
    
    a.print();
    
    Vec_Message1 emailSystem1(5);
    print(cout,emailSystem1);
    
    
    Message1 _email5("Calvin", "Sateesh", "project2_2018", "Am I doing this correctly?");
    Vec_Message1 emailSystem2(1, _email5);
    print(cout, emailSystem2);
    
    Message1 _email6("Calvin", "Lindbergh", "Hello", "Hello Brother!");
    emailSystem2.push_back(_email6);
    print(cout, emailSystem2);
    
    Message1 _email7("Calvin", "Julie", "Hi", "Hi Sister!");
    emailSystem2.push_back(_email7);
    cout << "Front: " << endl << emailSystem2.front() << endl;
    cout << "Back: " << endl << emailSystem2.back() << endl;
    
    Message1 _email8("Calvin", "Ricky", "Yo", "Yo man!");
    emailSystem2.push_back(_email8);
    print(cout, emailSystem2);
    
    emailSystem2.pop_back();
    cout << "Back after pop_back: " << endl << emailSystem2.back() << endl;
    
    emailSystem2.clear();
    cout << "Size of emailSystem2 after clear: " << emailSystem2.size() << endl << endl;
    
    
    Vec_Message1 emailSystem3(1, _email7);
    print(cout,emailSystem3);
    
    emailSystem2 = emailSystem3;
    cout << "After assigning emailSystem3 to emailSystem2: " << endl;
    print(cout, emailSystem2);
    
    cout << "Constructing emailSystem4 the same as emailSystem2: " << endl;
    Vec_Message1 emailSystem4 = emailSystem2;
    print(cout, emailSystem4);
    
    Message1 _email9("Calvin", "Maw", "Howdy!", "Howdy mom!");
    emailSystem4.push_back(_email9);
    cout << emailSystem4.at(1);
    
    cout << endl;
    print(cout, emailSystem4);
    
    emailSystem1.clear();
    emailSystem2.clear();
    emailSystem3.clear();
    emailSystem4.clear();
    
    return 0;
    
    
    
    
    
    
}

