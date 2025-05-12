#include "Pt1_Q3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>
#include <locale>
using namespace std;



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
