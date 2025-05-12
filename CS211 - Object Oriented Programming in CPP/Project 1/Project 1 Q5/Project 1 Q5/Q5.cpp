#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double sqrt_Babylonian(double a);

int main() {
    double a = 23733402;
    double solution = sqrt_Babylonian(a);
    cout << "The final value = " << solution << endl;
    return 0;
}

double sqrt_Babylonian(double a) {
    double x = 1, error = .0001;
    int i = 0;
    bool trigger = true;

    
    while (trigger) {
        double temp = x;
        x = (x + a/x) / 2;
        i++;
        cout << "i = " << i << "; " << "x = " << fixed << setprecision(4) << x << endl;
        if (abs(x-temp) <= .0004) {
            trigger = false;
        }
    }
    
    return x;
    
}
