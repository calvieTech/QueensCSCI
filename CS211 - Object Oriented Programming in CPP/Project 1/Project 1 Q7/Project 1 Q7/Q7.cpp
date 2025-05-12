#include <iostream>
#include <cmath>
using namespace std;

bool divisible_11(int n, int &s);

int main() {
    int n = 23733402, s = 0;
    bool output = divisible_11(n, s);
    cout << output;
    return 0;
}

bool divisible_11(int n, int &s) {
    int s1 = 0;
    int s2 = 0;
    bool isOdd = 1;
    while(n > 0) {
        if(isOdd == 1) {
            s1 += n%10;
            isOdd = 0;
        } else {
            s2 += n%10;
            isOdd = 1;
        }
        n = n/10;
    }
    s = abs(s1-s2);
    if(s == 0) {
        return true;
    } else if(s < 11) {
        return false;
    } else {
        n = s;
        s = 0;
        return divisible_11(n, s);
    }
}
