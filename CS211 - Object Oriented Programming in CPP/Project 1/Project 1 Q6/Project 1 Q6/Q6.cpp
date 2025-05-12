#include <iostream>
using namespace std;

bool divisible_9(int n, int &s);

int main() {
    int n = 23733402, sum = 0;
    cout << "Output = " << divisible_9(n, sum) << endl;
    return 0;
}

bool divisible_9(int n, int &s) {
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    
    if (s < 9) {
        return false;
    }
    else if (s == 9) {
        return true;
    }
    else {
        n = s;
        s = 0;
        return divisible_9(n, s);
    }
}
