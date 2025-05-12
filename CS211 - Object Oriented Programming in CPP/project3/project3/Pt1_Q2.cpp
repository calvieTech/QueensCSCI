#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>
#include <locale>
using namespace std;

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




int main() {
    /*
    Name testing("cALvIN");
    testing.set(testing.name());
    cout << testing.address() << endl;
    */
    
    
    return 0;
    
    
}


