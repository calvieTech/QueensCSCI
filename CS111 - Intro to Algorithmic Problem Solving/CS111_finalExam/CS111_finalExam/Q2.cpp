#include <iostream>
using namespace std;


//output:
// a) ry
// b) Aes
// c) abcabc
// d) 1
// e) 3

//compiled to a.out and executed with the command ./a.out abcabc abc123


int main(int argc, char *argv[]) {
    
    string words[4] = {"A ", "very ", "easy", "question "};
    
    cout << words[1].substr(2) << endl; // a
    for (int i =0; i <= 2; i++) cout << words[i][i]; cout << endl; // b
    cout << argv[1] << endl; // c
    cout << words[3].find("u") << endl; // d
    cout << argc << endl; // e
    
    
    
    
    
    return 0;
}
